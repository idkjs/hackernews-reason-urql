
// [%%debugger.chrome];
// [@bs.module] external css: Js.t({..}) as 'a = "../styles/App.module.css";
[%bs.raw {|require('../styles/App.css')|}];

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let nowShowing =
    switch (url.path) {
    |[]|["/"] => ReasonReact.Router.replace("new/1");<LinkList />
    |["new",_] => <LinkList />
    // |["new",_] => <LinkListNew />
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