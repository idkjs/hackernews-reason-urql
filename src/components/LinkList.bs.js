// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Link from "./Link.bs.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Js_exn from "bs-platform/lib/es6/js_exn.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Js_json from "bs-platform/lib/es6/js_json.js";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as ReasonUrql from "reason-urql/src/ReasonUrql.bs.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

var ppx_printed_query = "query   {\nfeed  {\nlinks  {\nid  \ncreatedAt  \nurl  \ndescription  \n}\n\n}\n\n}\n";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "feed");
    var tmp;
    if (match$1 !== undefined) {
      var match$2 = Js_json.decodeObject(Caml_option.valFromOption(match$1));
      if (match$2 !== undefined) {
        var match$3 = Js_dict.get(Caml_option.valFromOption(match$2), "links");
        var tmp$1;
        if (match$3 !== undefined) {
          var value$1 = Caml_option.valFromOption(match$3);
          var match$4 = Js_json.decodeArray(value$1);
          tmp$1 = match$4 !== undefined ? match$4.map((function (value) {
                    var match = Js_json.decodeObject(value);
                    if (match !== undefined) {
                      var value$1 = Caml_option.valFromOption(match);
                      var match$1 = Js_dict.get(value$1, "id");
                      var tmp;
                      if (match$1 !== undefined) {
                        var value$2 = Caml_option.valFromOption(match$1);
                        var match$2 = Js_json.decodeString(value$2);
                        tmp = match$2 !== undefined ? match$2 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$2));
                      } else {
                        tmp = Js_exn.raiseError("graphql_ppx: Field id on type Link is missing");
                      }
                      var match$3 = Js_dict.get(value$1, "createdAt");
                      var match$4 = Js_dict.get(value$1, "url");
                      var tmp$1;
                      if (match$4 !== undefined) {
                        var value$3 = Caml_option.valFromOption(match$4);
                        var match$5 = Js_json.decodeString(value$3);
                        tmp$1 = match$5 !== undefined ? match$5 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$3));
                      } else {
                        tmp$1 = Js_exn.raiseError("graphql_ppx: Field url on type Link is missing");
                      }
                      var match$6 = Js_dict.get(value$1, "description");
                      var tmp$2;
                      if (match$6 !== undefined) {
                        var value$4 = Caml_option.valFromOption(match$6);
                        var match$7 = Js_json.decodeString(value$4);
                        tmp$2 = match$7 !== undefined ? match$7 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$4));
                      } else {
                        tmp$2 = Js_exn.raiseError("graphql_ppx: Field description on type Link is missing");
                      }
                      return {
                              id: tmp,
                              createdAt: match$3 !== undefined ? Caml_option.valFromOption(match$3) : Js_exn.raiseError("graphql_ppx: Field createdAt on type Link is missing"),
                              url: tmp$1,
                              description: tmp$2
                            };
                    } else {
                      return Js_exn.raiseError("graphql_ppx: Object is not a value");
                    }
                  })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$1));
        } else {
          tmp$1 = Js_exn.raiseError("graphql_ppx: Field links on type Feed is missing");
        }
        tmp = {
          links: tmp$1
        };
      } else {
        tmp = Js_exn.raiseError("graphql_ppx: Object is not a value");
      }
    } else {
      tmp = Js_exn.raiseError("graphql_ppx: Field feed on type Query is missing");
    }
    return {
            feed: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make(param) {
  return {
          query: ppx_printed_query,
          variables: null,
          parse: parse
        };
}

function makeWithVariables(param) {
  return {
          query: ppx_printed_query,
          variables: null,
          parse: parse
        };
}

function ret_type(f) {
  return /* module */Caml_chrome_debugger.localModule([], []);
}

var MT_Ret = /* module */Caml_chrome_debugger.localModule([], []);

var FEED_QUERY = /* module */Caml_chrome_debugger.localModule([
    "ppx_printed_query",
    "query",
    "parse",
    "make",
    "makeWithVariables",
    "ret_type",
    "MT_Ret"
  ], [
    ppx_printed_query,
    ppx_printed_query,
    parse,
    make,
    makeWithVariables,
    ret_type,
    MT_Ret
  ]);

function LinkList(Props) {
  var request = make(/* () */0);
  var match = Curry._4(ReasonUrql.Hooks[/* useQuery */1], request, undefined, undefined, /* () */0);
  var response = match[0][/* response */3];
  if (typeof response === "number") {
    if (response === 0) {
      return React.createElement("div", undefined, "Loading");
    } else {
      return React.createElement("div", undefined, "Not Found");
    }
  } else if (response.tag) {
    var match$1 = response[0][/* networkError */0];
    if (match$1 !== undefined) {
      return React.createElement("div", undefined, "Network Error");
    } else {
      return React.createElement("div", undefined, "No Network Error");
    }
  } else {
    var data = response[0];
    console.log("DATA", data.feed.links);
    var linksToRender = data.feed.links;
    var links = Belt_Array.map(linksToRender, (function (link) {
            return React.createElement(Link.make, {
                        link: link,
                        key: link.id
                      });
          }));
    return React.createElement("div", undefined, links);
  }
}

var make$1 = LinkList;

export {
  FEED_QUERY ,
  make$1 as make,
  
}
/* Link Not a pure module */