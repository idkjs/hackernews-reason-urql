// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Js_exn from "bs-platform/lib/es6/js_exn.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Js_json from "bs-platform/lib/es6/js_json.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

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

var ppx_printed_query$1 = "subscription   {\nnewVote  {\nlink  {\nid  \nvotes  {\nid  \nuser  {\nid  \n}\n\n}\n\n}\n\n}\n\n}\n";

function parse$1(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "newVote");
    var tmp;
    if (match$1 !== undefined) {
      var value$1 = Caml_option.valFromOption(match$1);
      var match$2 = Js_json.decodeNull(value$1);
      if (match$2 !== undefined) {
        tmp = undefined;
      } else {
        var match$3 = Js_json.decodeObject(value$1);
        var tmp$1;
        if (match$3 !== undefined) {
          var match$4 = Js_dict.get(Caml_option.valFromOption(match$3), "link");
          var tmp$2;
          if (match$4 !== undefined) {
            var match$5 = Js_json.decodeObject(Caml_option.valFromOption(match$4));
            if (match$5 !== undefined) {
              var value$2 = Caml_option.valFromOption(match$5);
              var match$6 = Js_dict.get(value$2, "id");
              var tmp$3;
              if (match$6 !== undefined) {
                var value$3 = Caml_option.valFromOption(match$6);
                var match$7 = Js_json.decodeString(value$3);
                tmp$3 = match$7 !== undefined ? match$7 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$3));
              } else {
                tmp$3 = Js_exn.raiseError("graphql_ppx: Field id on type Link is missing");
              }
              var match$8 = Js_dict.get(value$2, "votes");
              var tmp$4;
              if (match$8 !== undefined) {
                var value$4 = Caml_option.valFromOption(match$8);
                var match$9 = Js_json.decodeArray(value$4);
                tmp$4 = match$9 !== undefined ? match$9.map((function (value) {
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
                        })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$4));
              } else {
                tmp$4 = Js_exn.raiseError("graphql_ppx: Field votes on type Link is missing");
              }
              tmp$2 = {
                id: tmp$3,
                votes: tmp$4
              };
            } else {
              tmp$2 = Js_exn.raiseError("graphql_ppx: Object is not a value");
            }
          } else {
            tmp$2 = Js_exn.raiseError("graphql_ppx: Field link on type Vote is missing");
          }
          tmp$1 = {
            link: tmp$2
          };
        } else {
          tmp$1 = Js_exn.raiseError("graphql_ppx: Object is not a value");
        }
        tmp = Caml_option.some(tmp$1);
      }
    } else {
      tmp = undefined;
    }
    return {
            newVote: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make$1(param) {
  return {
          query: ppx_printed_query$1,
          variables: null,
          parse: parse$1
        };
}

function makeWithVariables$1(param) {
  return {
          query: ppx_printed_query$1,
          variables: null,
          parse: parse$1
        };
}

function ret_type$1(f) {
  return /* module */Caml_chrome_debugger.localModule([], []);
}

var MT_Ret$1 = /* module */Caml_chrome_debugger.localModule([], []);

var NEW_VOTES_SUBSCRIPTION = /* module */Caml_chrome_debugger.localModule([
    "ppx_printed_query",
    "query",
    "parse",
    "make",
    "makeWithVariables",
    "ret_type",
    "MT_Ret"
  ], [
    ppx_printed_query$1,
    ppx_printed_query$1,
    parse$1,
    make$1,
    makeWithVariables$1,
    ret_type$1,
    MT_Ret$1
  ]);

var ppx_printed_query$2 = "subscription   {\nnewLink  {\nid  \nurl  \ndescription  \ncreatedAt  \npostedBy  {\nid  \nname  \n}\n\nvotes  {\nid  \nuser  {\nid  \n}\n\n}\n\n}\n\n}\n";

function parse$2(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "newLink");
    var tmp;
    if (match$1 !== undefined) {
      var value$1 = Caml_option.valFromOption(match$1);
      var match$2 = Js_json.decodeNull(value$1);
      if (match$2 !== undefined) {
        tmp = undefined;
      } else {
        var match$3 = Js_json.decodeObject(value$1);
        var tmp$1;
        if (match$3 !== undefined) {
          var value$2 = Caml_option.valFromOption(match$3);
          var match$4 = Js_dict.get(value$2, "id");
          var tmp$2;
          if (match$4 !== undefined) {
            var value$3 = Caml_option.valFromOption(match$4);
            var match$5 = Js_json.decodeString(value$3);
            tmp$2 = match$5 !== undefined ? match$5 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$3));
          } else {
            tmp$2 = Js_exn.raiseError("graphql_ppx: Field id on type Link is missing");
          }
          var match$6 = Js_dict.get(value$2, "url");
          var tmp$3;
          if (match$6 !== undefined) {
            var value$4 = Caml_option.valFromOption(match$6);
            var match$7 = Js_json.decodeString(value$4);
            tmp$3 = match$7 !== undefined ? match$7 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$4));
          } else {
            tmp$3 = Js_exn.raiseError("graphql_ppx: Field url on type Link is missing");
          }
          var match$8 = Js_dict.get(value$2, "description");
          var tmp$4;
          if (match$8 !== undefined) {
            var value$5 = Caml_option.valFromOption(match$8);
            var match$9 = Js_json.decodeString(value$5);
            tmp$4 = match$9 !== undefined ? match$9 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$5));
          } else {
            tmp$4 = Js_exn.raiseError("graphql_ppx: Field description on type Link is missing");
          }
          var match$10 = Js_dict.get(value$2, "createdAt");
          var match$11 = Js_dict.get(value$2, "postedBy");
          var tmp$5;
          if (match$11 !== undefined) {
            var value$6 = Caml_option.valFromOption(match$11);
            var match$12 = Js_json.decodeNull(value$6);
            if (match$12 !== undefined) {
              tmp$5 = undefined;
            } else {
              var match$13 = Js_json.decodeObject(value$6);
              var tmp$6;
              if (match$13 !== undefined) {
                var value$7 = Caml_option.valFromOption(match$13);
                var match$14 = Js_dict.get(value$7, "id");
                var tmp$7;
                if (match$14 !== undefined) {
                  var value$8 = Caml_option.valFromOption(match$14);
                  var match$15 = Js_json.decodeString(value$8);
                  tmp$7 = match$15 !== undefined ? match$15 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$8));
                } else {
                  tmp$7 = Js_exn.raiseError("graphql_ppx: Field id on type User is missing");
                }
                var match$16 = Js_dict.get(value$7, "name");
                var tmp$8;
                if (match$16 !== undefined) {
                  var value$9 = Caml_option.valFromOption(match$16);
                  var match$17 = Js_json.decodeString(value$9);
                  tmp$8 = match$17 !== undefined ? match$17 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$9));
                } else {
                  tmp$8 = Js_exn.raiseError("graphql_ppx: Field name on type User is missing");
                }
                tmp$6 = {
                  id: tmp$7,
                  name: tmp$8
                };
              } else {
                tmp$6 = Js_exn.raiseError("graphql_ppx: Object is not a value");
              }
              tmp$5 = Caml_option.some(tmp$6);
            }
          } else {
            tmp$5 = undefined;
          }
          var match$18 = Js_dict.get(value$2, "votes");
          var tmp$9;
          if (match$18 !== undefined) {
            var value$10 = Caml_option.valFromOption(match$18);
            var match$19 = Js_json.decodeArray(value$10);
            tmp$9 = match$19 !== undefined ? match$19.map((function (value) {
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
                    })) : Js_exn.raiseError("graphql_ppx: Expected array, got " + JSON.stringify(value$10));
          } else {
            tmp$9 = Js_exn.raiseError("graphql_ppx: Field votes on type Link is missing");
          }
          tmp$1 = {
            id: tmp$2,
            url: tmp$3,
            description: tmp$4,
            createdAt: match$10 !== undefined ? Caml_option.valFromOption(match$10) : Js_exn.raiseError("graphql_ppx: Field createdAt on type Link is missing"),
            postedBy: tmp$5,
            votes: tmp$9
          };
        } else {
          tmp$1 = Js_exn.raiseError("graphql_ppx: Object is not a value");
        }
        tmp = Caml_option.some(tmp$1);
      }
    } else {
      tmp = undefined;
    }
    return {
            newLink: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make$2(param) {
  return {
          query: ppx_printed_query$2,
          variables: null,
          parse: parse$2
        };
}

function makeWithVariables$2(param) {
  return {
          query: ppx_printed_query$2,
          variables: null,
          parse: parse$2
        };
}

function ret_type$2(f) {
  return /* module */Caml_chrome_debugger.localModule([], []);
}

var MT_Ret$2 = /* module */Caml_chrome_debugger.localModule([], []);

var NEW_LINKS_SUBSCRIPTION = /* module */Caml_chrome_debugger.localModule([
    "ppx_printed_query",
    "query",
    "parse",
    "make",
    "makeWithVariables",
    "ret_type",
    "MT_Ret"
  ], [
    ppx_printed_query$2,
    ppx_printed_query$2,
    parse$2,
    make$2,
    makeWithVariables$2,
    ret_type$2,
    MT_Ret$2
  ]);

export {
  FEED_QUERY ,
  NEW_VOTES_SUBSCRIPTION ,
  NEW_LINKS_SUBSCRIPTION ,
  
}
/* No side effect */
