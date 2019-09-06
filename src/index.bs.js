// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as App from "./components/App.bs.js";
import * as Urql from "urql";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Fetch from "bs-fetch/src/Fetch.js";
import * as Token from "./Token.bs.js";
import * as Wonka from "wonka/src/wonka.js";
import * as React from "react";
import * as ReactDOMRe from "reason-react/src/ReactDOMRe.js";
import * as ReasonUrql from "reason-urql/src/ReasonUrql.bs.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Devtools from "@urql/devtools";
import * as ServiceWorker from "./serviceWorker";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";
import * as CacheExchange from "@urql/exchange-graphcache";

((require('./styles/index.css')));

((require('tachyons/css/tachyons.css')));

function register_service_worker(prim) {
  ServiceWorker.register();
  return /* () */0;
}

function unregister_service_worker(prim) {
  ServiceWorker.unregister();
  return /* () */0;
}

ReasonReactRouter.push("");

function debugExchange(exchangeInput) {
  var forward = exchangeInput.forward;
  return (function (ops) {
      return Wonka.tap((function (res) {
                      console.log("[debugExchange]: Completed operation: ", res);
                      return /* () */0;
                    }))(Curry._1(forward, Wonka.tap((function (op) {
                              console.log("[debugExchange]: Incoming operation: ", op);
                              return /* () */0;
                            }))(ops)));
    });
}

var token = Token.getToken(/* () */0);

var headers = {
  Authorization: "Bearer " + (String(token) + "")
};

var fetchOptions = Fetch.RequestInit[/* make */0](/* Post */2, Caml_option.some(headers), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* () */0);

var headerContextLink = /* FetchOpts */Caml_chrome_debugger.variant("FetchOpts", 0, [fetchOptions]);

function cache(param) {
  return CacheExchange.cacheExchange(param);
}

var client = Curry._4(ReasonUrql.Client[/* make */3], "http://localhost:4000", headerContextLink, /* array */[
      debugExchange,
      CacheExchange.cacheExchange(undefined),
      Devtools.devtoolsExchange,
      Urql.fetchExchange
    ], /* () */0);

ReactDOMRe.renderToElementWithId(React.createElement(Urql.Provider, {
          value: client,
          children: React.createElement(App.make, { })
        }), "root");

ServiceWorker.unregister();

export {
  register_service_worker ,
  unregister_service_worker ,
  debugExchange ,
  headerContextLink ,
  cache ,
  client ,
  
}
/*  Not a pure module */
