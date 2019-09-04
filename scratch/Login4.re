open ReasonUrql;

[@react.component]
let make = () => {
  // Used to switch between login and signup
  let (isLogin, setIsLogin) = React.useState(() => true);

  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  let (name, setName) = React.useState(() => "");
  let loginRequest = Mutations.Login.make(~email, ~password, ());
  let signupRequest = Mutations.SignUp.make(~email, ~password, ~name, ());
let (state, executeSignUpMutation) = Hooks.useMutation(~request=signupRequest);
let (state, executeLoginMutation) = Hooks.useMutation(~request=loginRequest);

  let handle = (cb, event) => {
    let value = ReactEvent.Form.target(event)##value;
    cb(_ => value);
  };
  let handleSignUp = () => {
    executeSignUpMutation() |> ignore;
    Js.Promise.then_(data => {
      Js.log2("TOKEN_DATA", data);
      let token = data##signup##token->Belt.Option.getExn;
      Token.setToken(token);
      Js.log2("TOKEN_DATA", token);
      Js.Promise.resolve();
    })
    |> ignore;
    ReasonReactRouter.push("/");
  };

  // let handleLogin = () => {
  //   executeLoginMutation() |> ignore;
  //   Js.Promise.then_(data => {
  //     Js.log2("TOKEN_DATA", data);
  //     let token = data##login##token->Belt.Option.getExn;
  //     Token.setToken(token);
  //     Js.log2("TOKEN_DATA", token);
  //     Js.Promise.resolve();
  //   })
  //   |> ignore;
  //   Js.log2("TOKEN_DATA", Token.getToken());
  //   ReasonReactRouter.push("/");
  // };
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
         ?
        //  <Mutation
        //      request={Mutations.SignUp.make(~email, ~password, ~name, ())}>
        //      ...{({executeMutation}) =>
               <button
                 type_="button"
                 className="pointer mr2 button"
                 disabled={state.fetching}
                 onClick={e_=>handleSignUp()}>
                 "signup"->React.string
               </button>
            //  }
          //  </Mutation>
         :
        //  <Mutation request={Mutations.Login.make(~email, ~password, ())}>
        //      ...{({executeMutation}) =>
               <button
                 type_="button"
                 className="pointer mr2 button"
                 disabled={state.fetching}
                 onClick={_e =>handleLogin()}>
                 "login"->React.string
               </button>
             }
          //  </Mutation>
           }
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