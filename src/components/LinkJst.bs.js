// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Js_exn from "bs-platform/lib/es6/js_exn.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Js_json from "bs-platform/lib/es6/js_json.js";
import * as ReasonUrql from "reason-urql/src/ReasonUrql.bs.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Token$ReasonHn from "../Token.bs.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

var ppx_printed_query = "mutation VoteMutation($linkId: ID!)  {\nvote(linkId: $linkId)  {\nlink  {\nid  \nvotes  {\nid  \nuser  {\nid  \n}\n\n}\n\n}\n\n}\n\n}\n";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "vote");
    var tmp;
    if (match$1 !== undefined) {
      var match$2 = Js_json.decodeObject(Caml_option.valFromOption(match$1));
      if (match$2 !== undefined) {
        var match$3 = Js_dict.get(Caml_option.valFromOption(match$2), "link");
        var tmp$1;
        if (match$3 !== undefined) {
          var match$4 = Js_json.decodeObject(Caml_option.valFromOption(match$3));
          if (match$4 !== undefined) {
            var value$1 = Caml_option.valFromOption(match$4);
            var match$5 = Js_dict.get(value$1, "id");
            var tmp$2;
            if (match$5 !== undefined) {
              var value$2 = Caml_option.valFromOption(match$5);
              var match$6 = Js_json.decodeString(value$2);
              tmp$2 = match$6 !== undefined ? match$6 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$2));
            } else {
              tmp$2 = Js_exn.raiseError("graphql_ppx: Field id on type Link is missing");
            }
            var match$7 = Js_dict.get(value$1, "votes");
            var tmp$3;
            if (match$7 !== undefined) {
              var value$3 = Caml_option.valFromOption(match$7);
              var match$8 = Js_json.decodeArray(value$3);
              tmp$3 = match$8 !== undefined ? match$8.map((function (value) {
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
                            tmp = Js_exn.raiseError("graphql_ppx: Field id on type Vote is missing");
                          }
                          var match$3 = Js_dict.get(value$1, "user");
                          var tmp$1;
                          if (match$3 !== undefined) {
                            var match$4 = Js_json.decodeObject(Caml_option.valFromOption(match$3));
                            if (match$4 !== undefined) {
                              var match$5 = Js_dict.get(Caml_option.valFromOption(match$4), "id");
                              var tmp$2;
                              if (match$5 !== undefined) {
                                var value$3 = Caml_option.valFromOption(match$5);
                                var match$6 = Js_json.decodeString(value$3);
                                tmp$2 = match$6 !== undefined ? match$6 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$3));
                              } else {
                                tmp$2 = Js_exn.raiseError("graphql_ppx: Field id on type User is missing");
                              }
                              tmp$1 = {
                                id: tmp$2
                              };
                            } else {
                              tmp$1 = Js_exn.raiseError("graphql_ppx: Object is not a value");
                            }
                          } else {
                            tmp$1 = Js_exn.raiseError("graphql_ppx: Field user on type Vote is missing");
                          }
                          return {
                                  id: tmp,
                                  user: tmp$1
                                };
                        } else {
                          return Js_exn.raiseError("graphql_ppx: Object is not a value");
                        }
                      })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$3));
            } else {
              tmp$3 = Js_exn.raiseError("graphql_ppx: Field votes on type Link is missing");
            }
            tmp$1 = {
              id: tmp$2,
              votes: tmp$3
            };
          } else {
            tmp$1 = Js_exn.raiseError("graphql_ppx: Object is not a value");
          }
        } else {
          tmp$1 = Js_exn.raiseError("graphql_ppx: Field link on type Vote is missing");
        }
        tmp = {
          link: tmp$1
        };
      } else {
        tmp = Js_exn.raiseError("graphql_ppx: Object is not a value");
      }
    } else {
      tmp = Js_exn.raiseError("graphql_ppx: Field vote on type Mutation is missing");
    }
    return {
            vote: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make(linkId, param) {
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[/* tuple */[
                  "linkId",
                  linkId
                ]]),
          parse: parse
        };
}

function makeWithVariables(variables) {
  var linkId = variables.linkId;
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[/* tuple */[
                  "linkId",
                  linkId
                ]]),
          parse: parse
        };
}

function ret_type(f) {
  return /* module */Caml_chrome_debugger.localModule([], []);
}

var MT_Ret = /* module */Caml_chrome_debugger.localModule([], []);

var VOTE_MUTATION = /* module */Caml_chrome_debugger.localModule([
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

function LinkJst(Props) {
  var link = Props.link;
  var index = Props.index;
  var match = Curry._1(ReasonUrql.Hooks[/* useMutation */0], make(link.id, /* () */0));
  var executeVoteMutation = match[1];
  var match$1 = Token$ReasonHn.isLoggedIn(/* () */0);
  return React.createElement("div", {
              className: "flex mt2 items-start"
            }, React.createElement("div", {
                  className: "flex items-center"
                }, React.createElement("span", {
                      className: "gray"
                    }, String(index + 1 | 0) + "."), match$1 ? React.createElement("div", {
                        className: "ml1 gray f11",
                        onClick: (function (param) {
                            Curry._1(executeVoteMutation, /* () */0);
                            return /* () */0;
                          })
                      }, "▲") : null), React.createElement("div", {
                  className: "ml1"
                }, React.createElement("div", undefined, link.description + (" (" + (link.url + ") "))), React.createElement("div", {
                      className: "f6 lh-copy gray"
                    }, String(link.votes.length) + " votes | by ")));
}

var make$1 = LinkJst;

export {
  VOTE_MUTATION ,
  make$1 as make,
  
}
/* react Not a pure module */
