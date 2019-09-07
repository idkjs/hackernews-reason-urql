// [%bs.raw {|require('../styles/App.css')|}];

// type route =
//   | LinkList(option(string))
//   | CreateLink
//   | SignUp
//   | Login
//   | Search
//   | NotFound;


// let parseUrl = (url: ReasonReactRouter.url) => {
//   switch (url.path) {
//   | []|["/"] => LinkList(None)
//   // | []|["/"] => LinkList(Some(id))
//   | ["new", id] => LinkList(Some(id))
//   | ["create"] => CreateLink
//   | ["signup"] => SignUp
//   | ["login"] => Login
//   | ["search"] => Search
//   | _ => NotFound
//   };
// };
// [@react.component]
// let make = () => {
//   let url = ReasonReactRouter.useUrl();
//   let route = parseUrl(url);
//   let nowShowing =
//     switch (route) {
//     | LinkList(None) => <LinkList />
//     | LinkList(Some("1")) => <LinkList />
//     | CreateLink => <CreateLink />
//     | SignUp => <SignUp />
//     | Login => <Login />
//     | Search => <Search />
//     | _ => "NotFound"->React.string
//     };
//   ();
//   <div className="center w85">
//     <Header />
//     <div className="ph3 pv1 background-gray"> nowShowing </div>
//   </div>;
// };