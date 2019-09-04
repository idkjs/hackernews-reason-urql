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
  let (loginState, executeLoginMutation) =
    Hooks.useMutation(~request=loginRequest);

  let (signUpState, executeSignupMutation) =
    Hooks.useMutation(~request=signupRequest);

  let handle = (cb, event) => {
    let value = ReactEvent.Form.target(event)##value;
    cb(_ => value);
  };
  let handleToken = token => {
    Js.log2("TOKEN_DATA", token);
    Token.setToken(token);
    ReasonReactRouter.push("/");
  };

  let submitSignUp = () => {
    executeSignupMutation()
    |> response => {
      Js.log2("submitSignUp",response)
    }
    |> _=> ReasonReactRouter.push("/");

    // ReasonReactRouter.push("/");
  };
  let submitLogin2 = () => {
    executeLoginMutation() |> ignore;
    Js.Promise.then_(response => {
        Js.log2("TOKEN_response", response);
        let token = response##data##signup##token->Belt.Option.getExn;
        handleToken(token)
        Js.Promise.resolve();
      })
      |> ignore;
    // ReasonReactRouter.push("/");
  };
  let submitLogin = () => {
    executeLoginMutation()
    |> response => {
      Js.log2("submitLogin",response)
      Js.log(response)
    };
    ReasonReactRouter.push("/");
  };

  let handleSignUp = _ => {
    executeSignupMutation() |> ignore;
    Js.Promise.then_(signUpState => {
      Js.log2("TOKEN_DATA", signUpState);
      let token = signUpState##data##signup##token->Belt.Option.getExn;
      // switch (data##signup##token) {
      // | Some(token) => onChange(token)
      // | None => ()
      // };
      // let token = data##signup##token->Belt.Option.getExn;
      handleToken(token);
      Js.Promise.resolve();
    })
    |> ignore;
  };
  let newSignUp = () => {
    setEmail(_ => BsFaker.Internet.exampleEmail());
    setPassword(_ => BsFaker.Internet.password());
    setName(_ => BsFaker.Name.firstName());
  };
  let logAll = () => {
    Js.log(name);
    Js.log(email);
    Js.log(password);
  };

  let handleLogin = _ => {
    executeLoginMutation() |> ignore;
    Js.Promise.then_(data => {
      Js.log2("TOKEN_DATA", data);
      let token = data##login##token->Belt.Option.getExn;
      handleToken(token);
      Js.Promise.resolve();
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
      <button
        type_="button"
        className="pointer mr2 button"
        disabled={loginState.fetching || signUpState.fetching}
        onClick={_event => isLogin ? submitLogin2() : submitSignUp()}>
        {isLogin ? "login"->React.string : "signup"->React.string}
      </button>
      <button
        type_="button"
        className="pointer button"
        onClick={_ => setIsLogin(isLogin => !isLogin)}>
        {isLogin
           ? "need to create an account?"->React.string
           : "already have an account?"->React.string}
      </button>
      <button
        type_="button" className="pointer button" onClick={_ => newSignUp()}>
        "generate Signup?"->React.string
      </button>
      <button
        type_="button" className="pointer button" onClick={_ => logAll()}>
        "Log New Signup?"->React.string
      </button>
    </div>
  </div>;
};