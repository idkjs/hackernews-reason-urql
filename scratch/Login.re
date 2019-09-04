open ReasonUrql;
open Client;

module Mutations = {
  module SignUp = [%graphql
    {|
      mutation SignupMutation($email: String!, $password: String!, $name: String!) {
          signup(email: $email, password: $password, name: $name) {
            token
          }
        }
    |}
  ];

  module Login = [%graphql
    {|
      mutation LoginMutation($email: String!, $password: String!) {
        login(email: $email, password: $password) {
          token
        }
      }
    |}
  ];
};
// module SIGNUP_MUTATION = [%graphql
// {|
// mutation SignupMutation($email: String!, $password: String!, $name: String!) {
//     signup(email: $email, password: $password, name: $name) {
//       token
//     }
//   }
// |}
// ];

// module LOGIN_MUTATION = [%graphql
// {|
//   mutation LoginMutation($email: String!, $password: String!) {
//     login(email: $email, password: $password) {
//       token
//     }
//   }
//   |}
// ];

[@react.component]
let make = () => {
  // Used to switch between login and signup
  let (isLogin, setIsLogin) = React.useState(() => true);

  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  let (name, setName) = React.useState(() => "");
  let loginRequest = Mutations.Login.make(~email, ~password, ());
  let signupRequest = Mutations.SignUp.make(~email, ~password, ~name, ());
  // let request = isLogin ? loginRequest : signupRequest;
  let (state, executeLoginMutation) =
    Hooks.useMutation(~request=loginRequest);

  let (state, executeSignupMutation) =
    Hooks.useMutation(~request=signupRequest);

  let mutateLogin = () => {
    executeLoginMutation() |> ignore;
    Js.Promise.then_(data => {
      Js.log2("TOKEN_DATA", data);
      let token = data##login##token;
      Js.log2("TOKEN_DATA", token);
      switch (token) {
      | Some(token) =>
        Token.setToken(token);
        ReasonReactRouter.push("/");
        Js.Promise.resolve();
      | None => Js.Promise.resolve()
      };
    })
    |> ignore;
  };

  let mutateSignUp = () => {
    executeSignupMutation() |> ignore;
    Js.Promise.then_(data => {
      Js.log2("TOKEN_DATA", data);
      let token = data##signup##token;
      Js.log2("TOKEN_DATA", token);
      switch (token) {
      | Some(token) =>
        Token.setToken(token);
        ReasonReactRouter.push("/");
        Js.Promise.resolve();
      | None => Js.Promise.resolve()
      };
    })
    |> ignore;
  };

  let handle = (cb, event) => {
    let value = ReactEvent.Form.target(event)##value;
    cb(_ => value);
  };

  // let executeMutation = () =>
  //   executeMutation(~client, ~request=mutationRequest, ())
  //   |> Wonka.subscribe((. data) =>
  //        switch (data.response) {
  //        | Data(d) =>
  //          switch (Js.Json.stringifyAny(d)) {
  //          | Some(s) => dispatch(SetMutation(s))
  //          | None => ()
  //          }
  //        | Error(e) =>
  //          switch (Js.Json.stringifyAny(e)) {
  //          | Some(s) => dispatch(SetMutation(s))
  //          | None => ()
  //          }
  //        | _ => ()
  //        }
      //  );
  let handleMutate = (executeMutation,~request) => {
    executeMutation(~client, ~request=mutationRequest, ()) |> ignore;
    Js.Promise.then_(data => {
      Js.log2("TOKEN_DATA", data);
      let token = data##signup##token;
      Js.log2("TOKEN_DATA", token);
      switch (token) {
      | Some(token) =>
        Token.setToken(token);
        ReasonReactRouter.push("/");
        Js.Promise.resolve();
      | None => Js.Promise.resolve()
      };
    })
    |> ignore;
  };
  <div>
    <h4 className="mv3">
      {isLogin ? "Login"->React.string : "Sign Up"->React.string}
    </h4>
    <div className="flex flex-column">
      {!isLogin
         ? <input
             value=name
             onChange={handle(setName)}
             type_="text"
             placeholder="Your name"
           />
         : React.null}
      <input
        value=email
        onChange={handle(setEmail)}
        type_="text"
        placeholder="Your email address"
      />
      <input
        value=password
        onChange={handle(setPassword)}
        type_="password"
        placeholder="Choose a safe password"
      />
    </div>
    <div className="flex mt3">
      {!isLogin
         ? <Mutation
             request={Mutations.SignUp.make(~email, ~password, ~name, ())}>
             ...{({executeMutation}) =>
               <button
                 type_="button"
                 className="pointer mr2 button"
                 disabled={state.fetching}
                 onClick={_event => handleMutate(executeMutation)}>
                 "signup"->React.string
               </button>
             }
           </Mutation>
         : <Mutation request={Mutations.Login.make(~email, ~password, ())}>
             ...{({executeMutation}) =>
               <button
                 type_="button"
                 className="pointer mr2 button"
                 disabled={state.fetching}
                 onClick={_event =>handleMutate(executeMutation)}>
                 "login"->React.string
               </button>
             }
           </Mutation>}
      // {!isLogin
      //  ? <button
      //      type_="button"
      //      className="pointer mr2 button"
      //      disabled={state.fetching}
      //      onClick={_ => mutateLogin()}>
      //      {isLogin ? "login"->React.string : "create account"->React.string}
      //    </button>
      //    : <button
      //        type_="button"
      //        className="pointer mr2 button"
      //        disabled={state.fetching}
      //        onClick={_ => mutateSignUp()}>
      //        {isLogin ? "login"->React.string : "create account"->React.string}
      //      </button>}
      <button
        type_="button"
        className="pointer button"
        disabled={state.fetching}
        onClick={_ => setIsLogin(isLogin => !isLogin)}>
        {isLogin
           ? "need to create an account?"->React.string
           : "already have an account?"->React.string}
      </button>
    </div>
  </div>;
};