// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

function payloadToJs(param) {
  return {
          skip: param[/* skip */0],
          first: param[/* first */1],
          orderBy: param[/* orderBy */2]
        };
}

function payloadFromJs(param) {
  return /* record */Caml_chrome_debugger.record([
            "skip",
            "first",
            "orderBy"
          ], [
            param.skip,
            param.first,
            param.orderBy
          ]);
}

export {
  payloadToJs ,
  payloadFromJs ,
  
}
/* No side effect */
