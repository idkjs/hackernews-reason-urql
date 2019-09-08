// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Token$ReasonHn from "../Token.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

function handleClick(href, $$event) {
  $$event.preventDefault();
  return ReasonReactRouter.push(href);
}

function Header$Link(Props) {
  var href = Props.href;
  var match = Props.className;
  var className = match !== undefined ? match : "";
  var children = Props.children;
  return React.createElement("a", {
              className: className,
              href: href,
              onClick: (function (param) {
                  return handleClick(href, param);
                })
            }, children);
}

var Link = /* module */Caml_chrome_debugger.localModule([
    "handleClick",
    "make"
  ], [
    handleClick,
    Header$Link
  ]);

function Header(Props) {
  var isLoggedIn = Token$ReasonHn.isLoggedIn(/* () */0);
  return React.createElement("div", {
              className: "flex pa1 justify-between nowrap orange"
            }, React.createElement("div", {
                  className: "flex flex-fixed black"
                }, React.createElement("div", {
                      className: "fw7 mr1"
                    }, "Reason Hacker News"), React.createElement(Header$Link, {
                      href: "/",
                      className: "ml1 no-underline black",
                      children: "new"
                    }), React.createElement("div", {
                      className: "ml1"
                    }, "|"), React.createElement(Header$Link, {
                      href: "/top",
                      className: "ml1 no-underline black",
                      children: "top"
                    }), React.createElement("div", {
                      className: "ml1"
                    }, "|"), React.createElement(Header$Link, {
                      href: "/search",
                      className: "ml1 no-underline black",
                      children: "search"
                    }), React.createElement("div", {
                      className: "ml1"
                    }, "|"), React.createElement(Header$Link, {
                      href: "/tweets",
                      className: "ml1 no-underline black",
                      children: "sorting"
                    }), isLoggedIn ? React.createElement("div", {
                        className: "flex"
                      }, React.createElement("div", {
                            className: "ml1"
                          }, "|"), React.createElement(Header$Link, {
                            href: "/create",
                            className: "ml1 no-underline black",
                            children: "submit"
                          })) : null), React.createElement("div", {
                  className: "flex flex-fixed"
                }, isLoggedIn ? React.createElement("div", {
                        className: "ml1 pointer black",
                        onClick: (function (param) {
                            Token$ReasonHn.deleteToken(/* () */0);
                            return ReasonReactRouter.push("/");
                          })
                      }, "logout") : React.createElement(Header$Link, {
                        href: "/login",
                        className: "ml1 no-underline black",
                        children: "login"
                      })));
}

var make = Header;

export {
  Link ,
  make ,
  
}
/* react Not a pure module */
