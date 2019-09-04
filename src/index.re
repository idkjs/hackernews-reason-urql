[%bs.raw {|require('./styles/index.css')|}];

[%bs.raw {|require('tachyons/css/tachyons.css')|}];
[@bs.module "./serviceWorker"]
external register_service_worker: unit => unit = "register";
[@bs.module "./serviceWorker"]
external unregister_service_worker: unit => unit = "unregister";
open ReasonUrql;
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

let contextHandler = token => {
  let headers = {
    "headers": {
      "Authorization": {j|Bearer $token|j},
    },
  };
  headers;
};

let fetchOptions =
  Fetch.RequestInit.make(
    ~method_=Post,
    ~headers=Fetch.HeadersInit.make(contextHandler(Token.getToken())),
    (),
  );
let client =
  Client.make(
    ~url="http://localhost:4000",
    ~fetchOptions=Client.FetchOpts(fetchOptions),
    ~exchanges=[|debugExchange, Exchanges.fetchExchange|],
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