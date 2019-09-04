// [@bs.module] external css: Js.t({..}) as 'a = "../styles/App.module.css";
[%bs.raw {|require('../styles/App.css')|}];

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let nowShowing =
    switch (url.path) {
    | [] => <LinkList />
    | ["create"] => <CreateLink />
    | ["signup"] => <SignUp />
    | ["login"] => <Login />
    | _ => "NotFound"->React.string
    };
  ();
  <div className="center w85">
    <Header isLoggedIn=Token.isLoggedIn() />
    <div className="ph3 pv1 background-gray">
     nowShowing
    </div>
  </div>;
};