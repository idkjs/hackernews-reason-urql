// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Js_json from "bs-platform/lib/es6/js_json.js";
import * as Login$ReasonHn from "./Login.bs.js";
import * as Header$ReasonHn from "./Header.bs.js";
import * as Search$ReasonHn from "./Search.bs.js";
import * as SignUp$ReasonHn from "./SignUp.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";
import * as CreateLink$ReasonHn from "./CreateLink.bs.js";
import * as LinkListNew$ReasonHn from "./LinkListNew.bs.js";

((require('../styles/App.css')));

function App(Props) {
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  var test = Js_json.test(url, /* Array */3);
  console.log("url", test);
  console.log("url", url);
  var match = url[/* path */0];
  var nowShowing;
  var exit = 0;
  if (match) {
    switch (match[0]) {
      case "/" : 
          if (match[1]) {
            nowShowing = "NotFound";
          } else {
            exit = 1;
          }
          break;
      case "create" : 
          nowShowing = match[1] ? "NotFound" : React.createElement(CreateLink$ReasonHn.make, { });
          break;
      case "login" : 
          nowShowing = match[1] ? "NotFound" : React.createElement(Login$ReasonHn.make, { });
          break;
      case "new" : 
          var match$1 = match[1];
          if (match$1 && !match$1[1]) {
            exit = 1;
          } else {
            nowShowing = "NotFound";
          }
          break;
      case "search" : 
          nowShowing = match[1] ? "NotFound" : React.createElement(Search$ReasonHn.make, { });
          break;
      case "signup" : 
          nowShowing = match[1] ? "NotFound" : React.createElement(SignUp$ReasonHn.make, { });
          break;
      default:
        nowShowing = "NotFound";
    }
  } else {
    exit = 1;
  }
  if (exit === 1) {
    nowShowing = React.createElement(LinkListNew$ReasonHn.make, { });
  }
  return React.createElement("div", {
              className: "center w85"
            }, React.createElement(Header$ReasonHn.make, { }), React.createElement("div", {
                  className: "ph3 pv1 background-gray"
                }, nowShowing));
}

var make = App;

export {
  make ,
  
}
/*  Not a pure module */
