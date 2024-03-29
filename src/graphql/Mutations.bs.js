// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Js_exn from "bs-platform/lib/es6/js_exn.js";
import * as Js_dict from "bs-platform/lib/es6/js_dict.js";
import * as Js_json from "bs-platform/lib/es6/js_json.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

var ppx_printed_query = "mutation SignupMutation($email: String!, $password: String!, $name: String!)  {\nsignup(email: $email, password: $password, name: $name)  {\ntoken  \n}\n\n}\n";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "signup");
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
          var match$4 = Js_dict.get(Caml_option.valFromOption(match$3), "token");
          var tmp$2;
          if (match$4 !== undefined) {
            var value$2 = Caml_option.valFromOption(match$4);
            var match$5 = Js_json.decodeNull(value$2);
            if (match$5 !== undefined) {
              tmp$2 = undefined;
            } else {
              var match$6 = Js_json.decodeString(value$2);
              tmp$2 = match$6 !== undefined ? match$6 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$2));
            }
          } else {
            tmp$2 = undefined;
          }
          tmp$1 = {
            token: tmp$2
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
            signup: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make(email, password, name, param) {
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "email",
                  email
                ],
                /* tuple */[
                  "password",
                  password
                ],
                /* tuple */[
                  "name",
                  name
                ]
              ]),
          parse: parse
        };
}

function makeWithVariables(variables) {
  var email = variables.email;
  var password = variables.password;
  var name = variables.name;
  return {
          query: ppx_printed_query,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "email",
                  email
                ],
                /* tuple */[
                  "password",
                  password
                ],
                /* tuple */[
                  "name",
                  name
                ]
              ]),
          parse: parse
        };
}

function ret_type(f) {
  return /* module */Caml_chrome_debugger.localModule([], []);
}

var MT_Ret = /* module */Caml_chrome_debugger.localModule([], []);

var SignUp = /* module */Caml_chrome_debugger.localModule([
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

var ppx_printed_query$1 = "mutation LoginMutation($email: String!, $password: String!)  {\nlogin(email: $email, password: $password)  {\ntoken  \n}\n\n}\n";

function parse$1(value) {
  var match = Js_json.decodeObject(value);
  if (match !== undefined) {
    var match$1 = Js_dict.get(Caml_option.valFromOption(match), "login");
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
          var match$4 = Js_dict.get(Caml_option.valFromOption(match$3), "token");
          var tmp$2;
          if (match$4 !== undefined) {
            var value$2 = Caml_option.valFromOption(match$4);
            var match$5 = Js_json.decodeNull(value$2);
            if (match$5 !== undefined) {
              tmp$2 = undefined;
            } else {
              var match$6 = Js_json.decodeString(value$2);
              tmp$2 = match$6 !== undefined ? match$6 : Js_exn.raiseError("graphql_ppx: Expected string, got " + JSON.stringify(value$2));
            }
          } else {
            tmp$2 = undefined;
          }
          tmp$1 = {
            token: tmp$2
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
            login: tmp
          };
  } else {
    return Js_exn.raiseError("graphql_ppx: Object is not a value");
  }
}

function make$1(email, password, param) {
  return {
          query: ppx_printed_query$1,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "email",
                  email
                ],
                /* tuple */[
                  "password",
                  password
                ]
              ]),
          parse: parse$1
        };
}

function makeWithVariables$1(variables) {
  var email = variables.email;
  var password = variables.password;
  return {
          query: ppx_printed_query$1,
          variables: Js_dict.fromArray(/* array */[
                /* tuple */[
                  "email",
                  email
                ],
                /* tuple */[
                  "password",
                  password
                ]
              ]),
          parse: parse$1
        };
}

function ret_type$1(f) {
  return /* module */Caml_chrome_debugger.localModule([], []);
}

var MT_Ret$1 = /* module */Caml_chrome_debugger.localModule([], []);

var Login = /* module */Caml_chrome_debugger.localModule([
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

export {
  SignUp ,
  Login ,
  
}
/* No side effect */
