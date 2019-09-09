[%bs.raw {|require('./styles/index.css')|}];

[%bs.raw {|require('tachyons/css/tachyons.css')|}];
[@bs.module "./serviceWorker"]
external register_service_worker: unit => unit = "register";
[@bs.module "./serviceWorker"]
external unregister_service_worker: unit => unit = "unregister";
open ReasonUrql;
open UrqlDevtools;
open Fetch;
open SubscriptionsTransportWS;
ReasonReactRouter.push("");

// open Client;
/* This is the native debugExchange that ships with `urql`, re-implemented in Reason.
     Typically, you'd just add Exchanges.debugExchange to the Client's exchange array.
   */
let debugExchange = exchangeInput => {
  let forward = Exchanges.forwardGet(exchangeInput);

  ops =>
    ops
    |> Wonka.tap((. op) =>
         Js.log2("[debugExchange]: Incoming operation: ", op)
       )
    |> forward
    |> Wonka.tap((. res) =>
         Js.log2("[debugExchange]: Completed operation: ", res)
       );
};

let headerContextLink = {
  let token = Token.getToken();
  let headers = {"Authorization": {j|Bearer $token|j}};

  let fetchOptions =
    Fetch.RequestInit.make(
      ~method_=Post,
      ~headers=Fetch.HeadersInit.make(headers),
      (),
    );
  // Return the function that gets passed to `fetchOptions` in `Client.make`
  Client.FetchOpts(fetchOptions);
};

let config = [%raw
  {|
  {
  updates: {
    Mutation: {
      post: ({ post }, _args, cache) => {
        const variables = { first: 10, skip: 0, orderBy: 'createdAt_DESC' }
        cache.updateQuery({ query: FEED_QUERY, variables }, data => {
          if (data !== null) {
            data.feed.links.unshift(post)
            data.feed.count++
            return data
          } else {
            return null
          }
        })
      }
    }
  }
}
|}
];
Js.log2("config", config);
let authToken = Token.getToken()->Belt.Option.getWithDefault("");
// let params = SubscriptionsTransportWS.connectionParams(~authToken=authToken);
// let cache = GraphCache.cacheExchange();
let cache = GraphCache.cacheExchange(config);
// let connectParams=connectionParamsSet(~authToken=tokenWS);
let options: subscriptionClientOptions =
  subscriptionClientOptions(
    ~reconnect=true,
    ~connectionParams={"authToken": authToken},
    (),
  );
let client =
  subscriptionClient(
    ~url="ws://localhost:4001/graphql",
    ~subscriptionClientConfig=subscriptionClientConfig(~options,()),
  );

let forwardSubscription = operation => client##request(operation);

let subscriptionExchangeOpts =
  Exchanges.subscriptionExchangeOpts(~forwardSubscription);

let subscriptionExchange =
  Exchanges.subscriptionExchange(subscriptionExchangeOpts);
let client =
  Client.make(
    ~url="http://localhost:4000",
    ~fetchOptions=headerContextLink,
    ~exchanges=
      Array.append(
        [|
          debugExchange,
          cache(~opts=None),
          devtoolsExchange,
          Exchanges.fetchExchange,
        |],
        [|subscriptionExchange|],
      ),
    (),
  );
ReactDOMRe.renderToElementWithId(
  <Provider value=client> <App /> </Provider>,
  "root",
);

// If you want your app to work offline and load faster, you can change
// unregister_service_worker() to register_service_worker() below. Note this
// comes with some pitfalls. Learn more about service workers:
// https://bit.ly/CRA-PWA
unregister_service_worker();