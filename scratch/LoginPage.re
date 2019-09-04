// open ReasonUrql;
// open Client;

// type state = {
//   mutation: string,
//   email: string,
//   password: string,
// };

// type action =
//   | SetMutation(string)
//   | SetEmail(string)
//   | SetPassword(string)
//   | ClearMutation;
// let initialState = {mutation: "", email: "", password: ""};
// [@react.component]
// let make = () => {
//   let (state, dispatch) =
//     React.useReducer(
//       (state, action) =>
//         switch (action) {
//         | SetMutation(mutation) => {...state, mutation}
//         | ClearMutation => {...state, mutation: ""}
//         | SetEmail(string) => {...state, email: string}
//         | SetPassword(string) => {...state, password: string}
//         },
//       initialState,
//     );
//   let request =
//     Mutations.Login.make(~email=state.email, ~password=state.password, ());

//   let handle = (cb, event) => {
//     let value = ReactEvent.Form.target(event)##value;
//     cb(_ => value);
//   };
//   let (state, executeMutation) = Hooks.useMutation(~request);
//   let executeMutation = () => {
//     executeMutation() |> ignore;
//     Js.Promise.then_(data => {
//       Js.log2("TOKEN_DATA", data);
//       let token = data##signup##token;
//       Js.log2("TOKEN_DATA", token);
//       switch (token) {
//       | Some(token) =>
//         Token.setToken(token);
//         ReasonReactRouter.push("/");
//         Js.Promise.resolve();
//       | None => Js.Promise.resolve()
//       };
//     })
//     |> ignore;
//     ReasonReactRouter.push("/");
//   };

//   <div>
//     <h4 className="mv3"> "Login"->React.string </h4>
//     <div className="flex flex-column">
//       <input
//         value=state.email
//         onChange={_e => dispatch(SetEmail(state.email))}
//         type_="text"
//         placeholder="Your email address"
//       />
//       <input
//         value=state.password
//         onChange={_e => dispatch(SetPassword(state.password))}
//         type_="password"
//         placeholder="Choose a safe password"
//       />
//       <button
//         type_="button"
//         className="pointer mr2 button"
//         disabled={state.fetching}
//         onChange={_e => executeMutation()|>ignore}>
//         "login"->React.string
//       </button>
//     </div>
//   </div>;
// };