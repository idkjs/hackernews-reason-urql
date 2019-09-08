// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Caml_int32 from "bs-platform/lib/es6/caml_int32.js";
import * as ReasonUrql from "reason-urql/src/ReasonUrql.bs.js";
import * as Caml_format from "bs-platform/lib/es6/caml_format.js";
import * as Link$ReasonHn from "./Link.bs.js";
import * as Types$ReasonHn from "../models/Types.bs.js";
import * as Queries$ReasonHn from "../graphql/Queries.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";

function LinkList(Props) {
  var match = Props.path;
  var path = match !== undefined ? match : ReasonReactRouter.useUrl(undefined, /* () */0)[/* path */0];
  var match$1 = React.useState((function () {
          return 0;
        }));
  var setCount = match$1[1];
  var count = match$1[0];
  var match$2 = React.useState((function () {
          return /* array */[];
        }));
  var setLinks = match$2[1];
  var page;
  if (path && path[0] === "new") {
    var match$3 = path[1];
    page = match$3 ? Caml_format.caml_int_of_string(match$3[0]) : 0;
  } else {
    page = 0;
  }
  var skip = Caml_int32.imul(page - 1 | 0, 10);
  var request = Queries$ReasonHn.FEED_QUERY[/* make */4](10, skip, /* createdAt_DESC */550411093, /* () */0);
  var match$4 = Curry._4(ReasonUrql.Hooks[/* useQuery */1], request, undefined, undefined, /* () */0);
  var response = match$4[0][/* response */3];
  var nextPage = React.useCallback((function (param) {
          var match = page <= (count / 10 | 0);
          if (match) {
            return ReasonReactRouter.push("/new/" + String(page + 1 | 0));
          } else {
            return ReasonReactRouter.push("/new/" + String(page));
          }
        }), /* array */[
        count,
        page
      ]);
  var previousPage = React.useCallback((function (param) {
          if (page > 1) {
            return ReasonReactRouter.push("/new/" + String(page - 1 | 0));
          } else {
            return 0;
          }
        }), /* array */[page]);
  var linkList = Belt_Array.mapWithIndex(match$2[0], (function (index, link) {
          return React.createElement(Link$ReasonHn.make, {
                      link: link,
                      index: skip + index | 0,
                      key: link[/* id */0]
                    });
        }));
  React.useEffect((function () {
          if (typeof response !== "number") {
            if (!response.tag) {
              var data = response[0];
              Types$ReasonHn.Feed[/* decodeLinks */4](data.feed.links);
              var linksToRender = Types$ReasonHn.Feed[/* decodeLinks */4](data.feed.links);
              Curry._1(setLinks, (function (param) {
                      return linksToRender;
                    }));
              var count = data.feed.count;
              Curry._1(setCount, (function (param) {
                      return count;
                    }));
            }
            
          }
          return undefined;
        }), /* array */[response]);
  return React.createElement(React.Fragment, undefined, React.createElement("div", undefined, linkList), React.createElement("div", {
                  className: "flex ml4 mv3 gray"
                }, React.createElement("div", {
                      className: "pointer mr2",
                      onClick: (function (param) {
                          return Curry._1(previousPage, /* () */0);
                        })
                    }, "Previous"), React.createElement("div", {
                      className: "pointer",
                      onClick: (function (param) {
                          return Curry._1(nextPage, /* () */0);
                        })
                    }, "Next")));
}

var make = LinkList;

export {
  make ,
  
}
/* react Not a pure module */
