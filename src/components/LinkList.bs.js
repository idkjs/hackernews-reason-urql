// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as List from "bs-platform/lib/es6/list.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Js_exn from "bs-platform/lib/es6/js_exn.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Js_json from "bs-platform/lib/es6/js_json.js";
import * as Belt_List from "bs-platform/lib/es6/belt_List.js";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Caml_int32 from "bs-platform/lib/es6/caml_int32.js";
import * as ReasonUrql from "reason-urql/src/ReasonUrql.bs.js";
import * as Caml_format from "bs-platform/lib/es6/caml_format.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Link$ReasonHn from "./Link.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";
import * as LinkDecoded$ReasonHn from "./LinkDecoded.bs.js";

var ppx_printed_query = "query FeedQuery($first: Int, $skip: Int, $orderBy: LinkOrderByInput)  {\nfeed(first: $first, skip: $skip, orderBy: $orderBy)  {\ncount  \nlinks  {\nid  \ncreatedAt  \nurl  \ndescription  \npostedBy  {\nid  \nname  \n}\n\nvotes  {\nid  \nuser  {\nid  \n}\n\n}\n\n}\n\n}\n\n}\n";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "feed");
    var tmp;
    if (match$1 !== undefined) {
      var match$2 = Js_json.decodeObject(Caml_option.valFromOption(match$1));
      if (match$2 !== undefined) {
        var value$1 = Caml_option.valFromOption(match$2);
        var match$3 = Js_dict.get(value$1, "count");
        var tmp$1;
        if (match$3 !== undefined) {
          var value$2 = Caml_option.valFromOption(match$3);
          var match$4 = Js_json.decodeNumber(value$2);
          tmp$1 = match$4 !== undefined ? match$4 | 0 : Js_exn.raiseError("graphql_ppx: Expected int, got " + JSON.stringify(value$2));
        } else {
          tmp$1 = Js_exn.raiseError("graphql_ppx: Field count on type Feed is missing");
        }
        var match$5 = Js_dict.get(value$1, "links");
        var tmp$2;
        if (match$5 !== undefined) {
          var value$3 = Caml_option.valFromOption(match$5);
          var match$6 = Js_json.decodeArray(value$3);
          tmp$2 = match$6 !== undefined ? match$6.map((function (value) {
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
                      var match$8 = Js_dict.get(value$1, "postedBy");
                      var tmp$3;
                      if (match$8 !== undefined) {
                        var value$5 = Caml_option.valFromOption(match$8);
                        var match$9 = Js_json.decodeNull(value$5);
                        if (match$9 !== undefined) {
                          tmp$3 = undefined;
                        } else {
                          var match$10 = Js_json.decodeObject(value$5);
                          var tmp$4;
                          if (match$10 !== undefined) {
                            var value$6 = Caml_option.valFromOption(match$10);
                            var match$11 = Js_dict.get(value$6, "id");
                            var tmp$5;
                            if (match$11 !== undefined) {
                              var value$7 = Caml_option.valFromOption(match$11);
                              var match$12 = Js_json.decodeString(value$7);
                              tmp$5 = match$12 !== undefined ? match$12 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$7));
                            } else {
                              tmp$5 = Js_exn.raiseError("graphql_ppx: Field id on type User is missing");
                            }
                            var match$13 = Js_dict.get(value$6, "name");
                            var tmp$6;
                            if (match$13 !== undefined) {
                              var value$8 = Caml_option.valFromOption(match$13);
                              var match$14 = Js_json.decodeString(value$8);
                              tmp$6 = match$14 !== undefined ? match$14 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$8));
                            } else {
                              tmp$6 = Js_exn.raiseError("graphql_ppx: Field name on type User is missing");
                            }
                            tmp$4 = {
                              id: tmp$5,
                              name: tmp$6
                            };
                          } else {
                            tmp$4 = Js_exn.raiseError("graphql_ppx: Object is not a value");
                          }
                          tmp$3 = Caml_option.some(tmp$4);
                        }
                      } else {
                        tmp$3 = undefined;
                      }
                      var match$15 = Js_dict.get(value$1, "votes");
                      var tmp$7;
                      if (match$15 !== undefined) {
                        var value$9 = Caml_option.valFromOption(match$15);
                        var match$16 = Js_json.decodeArray(value$9);
                        tmp$7 = match$16 !== undefined ? match$16.map((function (value) {
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
                                })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$9));
                      } else {
                        tmp$7 = Js_exn.raiseError("graphql_ppx: Field votes on type Link is missing");
                      }
                      return {
                              id: tmp,
                              createdAt: match$3 !== undefined ? Caml_option.valFromOption(match$3) : Js_exn.raiseError("graphql_ppx: Field createdAt on type Link is missing"),
                              url: tmp$1,
                              description: tmp$2,
                              postedBy: tmp$3,
                              votes: tmp$7
                            };
                    } else {
                      return Js_exn.raiseError("graphql_ppx: Object is not a value");
                    }
                  })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$3));
        } else {
          tmp$2 = Js_exn.raiseError("graphql_ppx: Field links on type Feed is missing");
        }
        tmp = {
          count: tmp$1,
          links: tmp$2
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

function json_of_LinkOrderByInput(value) {
  if (value >= 550411093) {
    if (value >= 929055841) {
      if (value >= 1043863310) {
        return "description_ASC";
      } else {
        return "url_DESC";
      }
    } else if (value >= 885860276) {
      return "description_DESC";
    } else {
      return "createdAt_DESC";
    }
  } else if (value >= 71429889) {
    return "url_ASC";
  } else {
    return "createdAt_ASC";
  }
}

function make(first, skip, orderBy, param) {
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "first",
                  first !== undefined ? first : null
                ],
                /* tuple */[
                  "skip",
                  skip !== undefined ? skip : null
                ],
                /* tuple */[
                  "orderBy",
                  orderBy !== undefined ? json_of_LinkOrderByInput(orderBy) : null
                ]
              ]),
          parse: parse
        };
}

function makeWithVariables(variables) {
  var first = variables.first;
  var skip = variables.skip;
  var orderBy = variables.orderBy;
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "first",
                  first !== undefined ? first : null
                ],
                /* tuple */[
                  "skip",
                  skip !== undefined ? skip : null
                ],
                /* tuple */[
                  "orderBy",
                  orderBy !== undefined ? json_of_LinkOrderByInput(orderBy) : null
                ]
              ]),
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
    "json_of_LinkOrderByInput",
    "make",
    "makeWithVariables",
    "ret_type",
    "MT_Ret"
  ], [
    ppx_printed_query,
    ppx_printed_query,
    parse,
    json_of_LinkOrderByInput,
    make,
    makeWithVariables,
    ret_type,
    MT_Ret
  ]);

function LinkList(Props) {
  var match = Props.path;
  var path = match !== undefined ? match : ReasonReactRouter.useUrl(undefined, /* () */0)[/* path */0];
  console.log("path", path);
  var isNewPage = Belt_List.has(path, "new", (function (prim, prim$1) {
          return prim === prim$1;
        })) === true;
  if (isNewPage) {
    console.log("page-var", Caml_format.caml_int_of_string(List.nth(path, 1)));
  }
  console.log("isNewPage", isNewPage);
  var skip = isNewPage ? Caml_int32.imul(Caml_format.caml_int_of_string(List.nth(path, 1)) - 1 | 0, 10) : 0;
  console.log("skip", skip);
  console.log("page-var", skip);
  var first = isNewPage ? 10 : 100;
  console.log("first", first);
  console.log("orderBy", /* createdAt_DESC */550411093);
  var firstPL = isNewPage ? 10 : 100;
  console.log("firstPL", firstPL);
  var skipPL = isNewPage ? Caml_int32.imul(Caml_format.caml_int_of_string(List.nth(path, 1)) - 1 | 0, 10) : 0;
  console.log("skipPL", skipPL);
  var orderByPL = isNewPage ? "createdAt_DESC" : "";
  console.log("orderByPL", orderByPL);
  var payload = React.useMemo((function () {
          var variables = { };
          variables["skip"] = skipPL;
          variables["first"] = firstPL;
          variables["orderBy"] = orderByPL;
          return variables;
        }), /* array */[path]);
  console.log("payload", payload);
  var request = make(first, skip, /* createdAt_DESC */550411093, /* () */0);
  var match$1 = Curry._4(ReasonUrql.Hooks[/* useQuery */1], request, undefined, undefined, /* () */0);
  var response = match$1[0][/* response */3];
  if (typeof response === "number") {
    if (response === 0) {
      return React.createElement("div", undefined, "Loading");
    } else {
      return React.createElement("div", undefined, "Not Found");
    }
  } else if (response.tag) {
    var match$2 = response[0][/* networkError */0];
    if (match$2 !== undefined) {
      return React.createElement("div", undefined, "Network Error");
    } else {
      return React.createElement("div", undefined, "No Network Error");
    }
  } else {
    var data = response[0];
    console.log("DATA", data);
    var linksToRender = LinkDecoded$ReasonHn.decodeLinks(data.feed.links);
    var links = Belt_Array.mapWithIndex(linksToRender, (function (index, link) {
            return React.createElement(Link$ReasonHn.make, {
                        link: link,
                        index: index,
                        key: link[/* id */0]
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
/* react Not a pure module */
