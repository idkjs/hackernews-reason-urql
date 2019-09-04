// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Mutations from "../Mutations.bs.js";
import * as ReasonUrql from "reason-urql/src/ReasonUrql.bs.js";
import * as Name$BsFaker from "bs-faker/src/Name.bs.js";
import * as Internet$BsFaker from "bs-faker/src/Internet.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";

function Login(Props) {
  var match = React.useState((function () {
          return true;
        }));
  var setIsLogin = match[1];
  var isLogin = match[0];
  var match$1 = React.useState((function () {
          return "";
        }));
  var setEmail = match$1[1];
  var email = match$1[0];
  var match$2 = React.useState((function () {
          return "";
        }));
  var setPassword = match$2[1];
  var password = match$2[0];
  var match$3 = React.useState((function () {
          return "";
        }));
  var setName = match$3[1];
  var name = match$3[0];
  var loginRequest = Mutations.Login[/* make */3](email, password, /* () */0);
  var signupRequest = Mutations.SignUp[/* make */3](email, password, name, /* () */0);
  var match$4 = Curry._1(ReasonUrql.Hooks[/* useMutation */0], loginRequest);
  var executeLoginMutation = match$4[1];
  var match$5 = Curry._1(ReasonUrql.Hooks[/* useMutation */0], signupRequest);
  var executeSignupMutation = match$5[1];
  var handle = function (cb, $$event) {
    var value = $$event.target.value;
    return Curry._1(cb, (function (param) {
                  return value;
                }));
  };
  var match$6 = !isLogin;
  return React.createElement("div", undefined, React.createElement("h4", {
                  className: "mv3"
                }, isLogin ? "Login" : "Sign Up"), React.createElement("div", {
                  className: "flex flex-column"
                }, match$6 ? React.createElement("input", {
                        placeholder: "Your name",
                        type: "text",
                        value: name,
                        onChange: (function (param) {
                            return handle(setName, param);
                          })
                      }) : null, React.createElement("input", {
                      placeholder: "Your email address",
                      type: "text",
                      value: email,
                      onChange: (function (param) {
                          return handle(setEmail, param);
                        })
                    }), React.createElement("input", {
                      placeholder: "Choose a safe password",
                      type: "password",
                      value: password,
                      onChange: (function (param) {
                          return handle(setPassword, param);
                        })
                    })), React.createElement("div", {
                  className: "flex mt3"
                }, React.createElement("button", {
                      className: "pointer mr2 button",
                      disabled: match$4[0][/* fetching */0] || match$5[0][/* fetching */0],
                      type: "button",
                      onClick: (function (_event) {
                          if (isLogin) {
                            Curry._1(executeLoginMutation, /* () */0);
                            return /* () */0;
                          } else {
                            var response = Curry._1(executeSignupMutation, /* () */0);
                            console.log("submitSignUp", response);
                            return ReasonReactRouter.push("/");
                          }
                        })
                    }, isLogin ? "login" : "signup"), React.createElement("button", {
                      className: "pointer button",
                      type: "button",
                      onClick: (function (param) {
                          return Curry._1(setIsLogin, (function (isLogin) {
                                        return !isLogin;
                                      }));
                        })
                    }, isLogin ? "need to create an account?" : "already have an account?"), React.createElement("button", {
                      className: "pointer button",
                      type: "button",
                      onClick: (function (param) {
                          Curry._1(setEmail, (function (param) {
                                  return Internet$BsFaker.exampleEmail(undefined, undefined, /* () */0);
                                }));
                          Curry._1(setPassword, (function (param) {
                                  return Internet$BsFaker.password(undefined, undefined, undefined, undefined, /* () */0);
                                }));
                          return Curry._1(setName, (function (param) {
                                        return Name$BsFaker.firstName(undefined, /* () */0);
                                      }));
                        })
                    }, "generate Signup?"), React.createElement("button", {
                      className: "pointer button",
                      type: "button",
                      onClick: (function (param) {
                          console.log(name);
                          console.log(email);
                          console.log(password);
                          return /* () */0;
                        })
                    }, "Log New Signup?")));
}

var make = Login;

export {
  make ,
  
}
/* react Not a pure module */
