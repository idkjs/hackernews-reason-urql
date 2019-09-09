// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Belt from "bs-platform/lib/es6/belt.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Caml_js_exceptions from "bs-platform/lib/es6/caml_js_exceptions.js";
import * as Caml_chrome_debugger from "bs-platform/lib/es6/caml_chrome_debugger.js";

function noop(param) {
  return /* () */0;
}

function noop1(param) {
  return /* () */0;
}

function noop2(param, param$1) {
  return /* () */0;
}

function noop3(param, param$1, param$2) {
  return /* () */0;
}

function flip(f, a, b) {
  return Curry._2(f, b, a);
}

function doThenReturn(a, f) {
  Curry._1(f, a);
  return a;
}

function inspect(t) {
  console.log(t);
  return t;
}

function inspect2(t, label) {
  console.log(label, t);
  return t;
}

function none(f) {
  Curry._1(f, /* () */0);
  return undefined;
}

var OptionUtils = /* module */Caml_chrome_debugger.localModule(["none"], [none]);

function flip$1(f, a, b) {
  return Curry._2(f, b, a);
}

function flip3(f, a, b, c) {
  return Curry._3(f, b, c, a);
}

var FunctionUtils = /* module */Caml_chrome_debugger.localModule([
    "flip",
    "flip3"
  ], [
    flip$1,
    flip3
  ]);

var DomUtils = /* module */Caml_chrome_debugger.localModule([], []);

function toOption(a) {
  var exit = 0;
  var v;
  try {
    v = Curry._1(a, /* () */0);
    exit = 1;
  }
  catch (exn){
    return undefined;
  }
  if (exit === 1) {
    return Caml_option.some(v);
  }
  
}

function toResult(a) {
  var exit = 0;
  var v;
  try {
    v = Curry._1(a, /* () */0);
    exit = 1;
  }
  catch (raw_t){
    var t = Caml_js_exceptions.internalToOCamlException(raw_t);
    return /* Error */Caml_chrome_debugger.variant("Error", 1, [t]);
  }
  if (exit === 1) {
    return /* Ok */Caml_chrome_debugger.variant("Ok", 0, [v]);
  }
  
}

var Exceptionable = /* module */Caml_chrome_debugger.localModule([
    "toOption",
    "toResult"
  ], [
    toOption,
    toResult
  ]);

var Id = Belt.Id;

var $$Array = Belt.$$Array;

var SortArray = Belt.SortArray;

var MutableQueue = Belt.MutableQueue;

var MutableStack = Belt.MutableStack;

var List = Belt.List;

var $$Range = Belt.$$Range;

var $$Set = Belt.$$Set;

var $$Map = Belt.$$Map;

var MutableSet = Belt.MutableSet;

var MutableMap = Belt.MutableMap;

var HashSet = Belt.HashSet;

var HashMap = Belt.HashMap;

var $$Option = Belt.$$Option;

var Result = Belt.Result;

var Int = Belt.Int;

var Float = Belt.Float;

var Debug = Belt.Debug;

export {
  Id ,
  $$Array ,
  SortArray ,
  MutableQueue ,
  MutableStack ,
  List ,
  $$Range ,
  $$Set ,
  $$Map ,
  MutableSet ,
  MutableMap ,
  HashSet ,
  HashMap ,
  $$Option ,
  Result ,
  Int ,
  Float ,
  Debug ,
  noop ,
  noop1 ,
  noop2 ,
  noop3 ,
  flip ,
  doThenReturn ,
  inspect ,
  inspect2 ,
  OptionUtils ,
  FunctionUtils ,
  DomUtils ,
  Exceptionable ,
  
}
/* No side effect */
