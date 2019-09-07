
// [%%debugger.chrome];
// [@bs.module] external css: Js.t({..}) as 'a = "../styles/App.module.css";
[%bs.raw {|require('../styles/App.css')|}];

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let test = Js.Json.test(url,Array);
    Js.log2("url", test);
    Js.log2("url", url);
    // Js.log2(
    // "url.path->Belt.List.map_Js.Global.decodeURI",
    //  url.path->Belt.List.map(Js.Global.decodeURI));
  let nowShowing =
    switch (url.path) {
    | []|["/"]
    |["new",_] => <LinkListNew />
    | ["create"] => <CreateLink />
    | ["signup"] => <SignUp />
    | ["login"] => <Login />
    | ["search"] => <Search />
    | _ => "NotFound"->React.string
    };
  ();
  <div className="center w85">
    <Header />
    <div className="ph3 pv1 background-gray"> nowShowing </div>
  </div>;
};