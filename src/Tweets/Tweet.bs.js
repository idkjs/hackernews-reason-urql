// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

var dummyTweets = /* array */[
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_1",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_2",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_3",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_4",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_5",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_6",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_7",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_8",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_9",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ]),
  /* record */Caml_chrome_debugger.record([
      "id",
      "text",
      "votes"
    ], [
      "id_10",
      "Some insightful tweet",
      [
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"]),
        /* record */Caml_chrome_debugger.record(["id"], ["ck0a0ychmjv5b0b09zlz6ps6m"])
      ]
    ])
];

function voteCount(tweet) {
  return tweet[/* votes */2].length;
}

function Tweet$Tweet(Props) {
  var tweet = Props.tweet;
  var index = Props.index;
  return React.createElement("div", {
              className: "flex mt2 items-start"
            }, React.createElement("div", {
                  className: "flex items-center"
                }, React.createElement("span", {
                      className: "gray"
                    }, String(index + 1 | 0) + ".")), React.createElement("div", {
                  className: "ml1"
                }, React.createElement("div", undefined, tweet[/* text */1]), React.createElement("div", {
                      className: "f6 lh-copy gray"
                    }, String(tweet[/* votes */2].length) + " votes | by "), React.createElement("div", {
                      className: "f6 lh-copy gray"
                    }, String(tweet[/* votes */2].length) + " votes | by ")));
}

var Tweet = /* module */Caml_chrome_debugger.localModule(["make"], [Tweet$Tweet]);

export {
  dummyTweets ,
  voteCount ,
  Tweet ,
  
}
/* react Not a pure module */