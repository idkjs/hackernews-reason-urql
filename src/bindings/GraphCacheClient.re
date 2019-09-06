type t;

/* Helpers for supporting polymorphic fetchOptions. */
type fetchOptions('a) =
  | FetchOpts(Fetch.requestInit): fetchOptions(Fetch.requestInit)
  | FetchFn(unit => Fetch.requestInit)
    : fetchOptions(unit => Fetch.requestInit);

let unwrapFetchOptions =
    (type a, fetchOptions: option(fetchOptions(a))): option(a) =>
  switch (fetchOptions) {
  | Some(FetchOpts(opts)) => Some(opts)
  | Some(FetchFn(fn)) => Some(fn)
  | None => None
  };

/* Types used and exposed by the urql client. */
module Types = {
  /* The result of executing a GraphQL request.
     Consists of optional data and errors fields. */
  [@bs.deriving abstract]
  type executionResult = {
    errors: Js.Nullable.t(array(UrqlCombinedError.graphqlError)),
    data: Js.Nullable.t(Js.Json.t),
  };

  /* OperationType for the active operation.
     Use with operationTypeToJs for proper conversion to strings. */
  [@bs.deriving jsConverter]
  type operationType = [
    | [@bs.as "subscription"] `Subscription
    | [@bs.as "query"] `Query
    | [@bs.as "mutation"] `Mutation
    | [@bs.as "teardown"] `Teardown
  ];

  /* Additional operation metadata to pass to the active operation.
     We currently do not support additional untyped options. */
  [@bs.deriving abstract]
  type operationContext = {
    [@bs.optional]
    fetchOptions: Fetch.requestInit,
    requestPolicy: UrqlTypes.requestPolicy,
    url: string,
  };

  /* A partial operation context, which can be passed as the second optional argument
     to executeQuery, executeMutation, and executeSubscription. Simply makes all
     properties on operationContext optional */
  [@bs.deriving abstract]
  type partialOperationContext = {
    [@bs.optional] [@bs.as "fetchOptions"]
    partialOpFetchOptions: Fetch.requestInit,
    [@bs.optional] [@bs.as "requestPolicy"]
    partialOpRequestPolicy: UrqlTypes.requestPolicy,
    [@bs.optional] [@bs.as "url"]
    partialOpUrl: string,
  };

  /* The active GraphQL operation. */
  [@bs.deriving abstract]
  type operation = {
    key: int,
    query: string,
    [@bs.optional]
    variables: Js.Json.t,
    operationName: operationType,
    context: operationContext,
  };

  /* The result of the GraphQL operation. */
  [@bs.deriving abstract]
  type operationResult = {
    operation,
    data: Js.Nullable.t(Js.Json.t),
    error: Js.Nullable.t(UrqlCombinedError.t),
  };

  /* The record representing the response returned by the client _after_
     it has been converted by UrqlConverts.urqlClientResponseToReason. */
  type response('response) =
    | Data('response)
    | Error(UrqlCombinedError.combinedError)
    | NotFound;

  type clientResponse('response) = {
    data: option('response),
    error: option(UrqlCombinedError.combinedError),
    response: response('response),
  };
};

/* A module for binding exchange types and urql's exposed exchanges. Since this module
   references UrqlClient and UrqlClient references this module,
   they need to be co-located to avoid a cyclic dependency error. */
module UrqlExchanges = {
  type exchangeIO =
    Wonka.Types.sourceT(Types.operation) =>
    Wonka.Types.sourceT(Types.operationResult);

  [@bs.deriving abstract]
  type exchangeInput = {
    forward: exchangeIO,
    client: t,
  };

  type exchange = exchangeInput => exchangeIO;

  [@bs.module "urql"] external cacheExchange: exchange = "";
  [@bs.module "urql"] external debugExchange: exchange = "";
  [@bs.module "urql"] external dedupExchange: exchange = "";
  [@bs.module "urql"] external fallbackExchangeIO: exchangeIO = "";
  [@bs.module "urql"] external fetchExchange: exchange = "";
  [@bs.module "urql"]
  external composeExchanges: array(exchange) => exchange = "";
  [@bs.module "urql"] external defaultExchanges: array(exchange) = "";

  /* Specific types for the subscriptionExchange. */
  [@bs.deriving abstract]
  type observerLike('value) = {
    next: 'value => unit,
    error: Js.Exn.t => unit,
    complete: unit => unit,
  };

  [@bs.deriving abstract]
  type observableLike('value) = {
    subscribe:
      observerLike('value) => {. [@bs.meth] "unsubscribe": unit => unit},
  };

  [@bs.deriving abstract]
  type subscriptionOperation = {
    query: string,
    [@bs.optional]
    variables: Js.Json.t,
    key: string,
    context: Types.operationContext,
  };

  type subscriptionForwarder =
    subscriptionOperation => observableLike(Types.executionResult);

  [@bs.deriving abstract]
  type subscriptionExchangeOpts = {
    forwardSubscription: subscriptionForwarder,
  };

  [@bs.module "urql"]
  external subscriptionExchange: subscriptionExchangeOpts => exchange = "";
};

[@bs.deriving abstract]
type clientOptions('a) = {
  url: string,
  [@bs.optional]
  fetchOptions: 'a,
  [@bs.optional]
  exchanges: array(UrqlExchanges.exchange),
};

[@bs.new] [@bs.module "urql"]
external client: clientOptions('a) => t = "Client";

/* `make` is equivalent to urql's `createClient`.
   We opt to use `make` here to adhere to standards in the Reason community. */
let make =
    (
      ~url,
      ~fetchOptions=?,
      ~exchanges=[|
                   UrqlExchanges.dedupExchange,
                   UrqlExchanges.cacheExchange,
                   UrqlExchanges.fetchExchange,
                 |],
      (),
    ) => {
  let options =
    clientOptions(
      ~url,
      ~fetchOptions=unwrapFetchOptions(fetchOptions),
      ~exchanges,
      (),
    );
  client(options);
};

/* A function to convert the JS response from the client to a Reason record. */
let urqlClientResponseToReason =
    (~parse: Js.Json.t => 'response, ~result: Types.operationResult) => {
  open Types;

  let data = result->dataGet->Js.Nullable.toOption->Belt.Option.map(parse);
  let error =
    result
    ->errorGet
    ->Js.Nullable.toOption
    ->Belt.Option.map(UrqlCombinedError.combinedErrorToRecord);

  let response =
    switch (data, error) {
    | (Some(data), _) => Data(data)
    | (None, Some(error)) => Error(error)
    | (None, None) => NotFound
    };

  {data, error, response};
};

/* Execution methods on the client. These allow you to imperatively execute GraphQL
   operations outside of components or hooks. */
[@bs.send]
external executeQueryJs:
  (
    ~client: t,
    ~query: UrqlTypes.graphqlRequest,
    ~opts: Types.partialOperationContext=?,
    unit
  ) =>
  Wonka.Types.sourceT(Types.operationResult) =
  "executeQuery";

let executeQuery =
    (
      ~client: t,
      ~request: UrqlTypes.request('response),
      ~opts: option(Types.partialOperationContext)=?,
      (),
    )
    : Wonka.Types.sourceT(Types.clientResponse('response)) => {
  let req =
    UrqlRequest.createRequest(
      ~query=request##query,
      ~variables=request##variables,
      (),
    );
  let parse = request##parse;

  executeQueryJs(~client, ~query=req, ~opts?, ())
  |> Wonka.map((. result) => urqlClientResponseToReason(~parse, ~result));
};

[@bs.send]
external executeMutationJs:
  (
    ~client: t,
    ~mutation: UrqlTypes.graphqlRequest,
    ~opts: Types.partialOperationContext=?,
    unit
  ) =>
  Wonka.Types.sourceT(Types.operationResult) =
  "executeMutation";

let executeMutation =
    (
      ~client: t,
      ~request: UrqlTypes.request('response),
      ~opts: option(Types.partialOperationContext)=?,
      (),
    )
    : Wonka.Types.sourceT(Types.clientResponse('response)) => {
  let req =
    UrqlRequest.createRequest(
      ~query=request##query,
      ~variables=request##variables,
      (),
    );
  let parse = request##parse;

  executeMutationJs(~client, ~mutation=req, ~opts?, ())
  |> Wonka.map((. result) => urqlClientResponseToReason(~parse, ~result));
};

[@bs.send]
external urqlExecuteSubscription:
  (
    ~client: t,
    ~subscription: UrqlTypes.graphqlRequest,
    ~opts: Types.partialOperationContext=?,
    unit
  ) =>
  Wonka.Types.sourceT(Types.operationResult) =
  "executeSubscription";

let executeSubscription =
    (
      ~client: t,
      ~request: UrqlTypes.request('response),
      ~opts: option(Types.partialOperationContext)=?,
      (),
    )
    : Wonka.Types.sourceT(Types.clientResponse('response)) => {
  let req =
    UrqlRequest.createRequest(
      ~query=request##query,
      ~variables=request##variables,
      (),
    );
  let parse = request##parse;

  urqlExecuteSubscription(~client, ~subscription=req, ~opts?, ())
  |> Wonka.map((. result) => urqlClientResponseToReason(~parse, ~result));
};

/* Additional methods exposed on the Client. These are currently here mostly for
   posterity. You'd use them infrequently, if at all, in a typical workflow. */
[@bs.send]
external executeRequestOperation:
  (~client: t, ~operation: Types.operation) =>
  Wonka.Types.sourceT(Types.operationResult) =
  "";

[@bs.send]
external reexecuteOperation: (~client: t, ~operation: Types.operation) => unit =
  "";

[@bs.send]
external createRequestOperationJs:
  (
    ~client: t,
    ~operationType: string,
    ~request: UrqlTypes.graphqlRequest,
    ~opts: Types.partialOperationContext=?,
    unit
  ) =>
  Types.operation =
  "createRequestOperation";

let createRequestOperation = (~client, ~operationType, ~request, ~opts=?, ()) => {
  let op = Types.operationTypeToJs(operationType);
  createRequestOperationJs(~client, ~operationType=op, ~request, ~opts?, ());
};

[@bs.send]
external dispatchOperation: (~client: t, ~operation: Types.operation) => unit =
  "";