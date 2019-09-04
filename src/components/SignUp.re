type action =
  | ToggleRemeber
  | Error(string)
  | SetEmail(string)
  | SetName(string)
  | SetPassword(string);

type state = {
  remember: bool,
  email: string,
  password: string,
  name: string,
  error: option(string),
};

let reducer = (state, action) =>
  switch (action) {
  | ToggleRemeber => {...state, remember: !state.remember}
  | SetEmail(email) => {...state, email}
  | SetName(name) => {...state, name}
  | SetPassword(password) => {...state, password}
  | Error(error) => {...state, error: Some(error)}
  };

let isFetching =
  fun
  | UrqlTypes.Fetching => true
  | _ => false;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      reducer,
      {remember: false, email: "", password: "", name: "",error: None},
    );
  let request =
    Mutations.SignUp.make(~name=state.name,~email=state.email, ~password=state.password, ());
  let (signupResponse, signupMutation) =
    ReasonUrql.Hooks.useMutation(~request);

  let login = (~token) => Token.setToken(token);
/* This is the equivalent of ReactJS's `ComponentDidUpdate` here:https://reactjs.org/docs/react-component.html#componentdidupdate
This will allow the change of the state/props only if certain props are passed or changed to. */
  React.useEffect1(
    () => {
      switch (signupResponse.response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) =>
        dispatch(Error({js|Combinação de email e senha invalidos|js}))
      | Data(resp) =>
        resp##signup
        ->Belt.Option.map(signupResp => {
            // let user = signupResp##user;
            let token = signupResp##token->Belt.Option.getExn;
            login(~token);
            ReasonReactRouter.push("/");
          })
        ->ignore
      };

      None;
    },
    [|signupResponse.response|], // Here we are listing dependency on which component will be re-rendered.
  );

  let newSignUp = () => {
    dispatch(SetEmail(BsFaker.Internet.exampleEmail()));
    dispatch(SetPassword(BsFaker.Internet.password()));
    dispatch(SetName(BsFaker.Name.firstName()));
  };
  let logAll = () => {
    Js.log(state.name);
    Js.log(state.email);
    Js.log(state.password);
  };

  <div>
    <h4 className="mv3"> "Login"->React.string </h4>
    <div className="flex flex-column">
      <input
        value={state.name}
        onChange={e => {
          let name = ReactEvent.Form.currentTarget(e)##value;
          dispatch(SetName(name));
        }}
        type_="text"
        placeholder="Your email address"
      />
      <input
        value={state.email}
        onChange={e => {
          let email = ReactEvent.Form.currentTarget(e)##value;
          dispatch(SetEmail(email));
        }}
        type_="text"
        placeholder="Your email address"
      />
      <input
        value={state.password}
        onChange={e => {
          let password = ReactEvent.Form.currentTarget(e)##value;
          dispatch(SetPassword(password));
        }}
        type_="password"
        placeholder="Choose a safe password"
      />
    </div>
    <div className="flex mt3">
      <button
        type_="button"
        className="pointer mr2 button"
        disabled={isFetching(signupResponse.response)}
        onClick={e => {
              ReactEvent.Mouse.preventDefault(e);
              signupMutation() |> ignore;
            }}>
        {"signup"->React.string}
      </button>
      <button
        type_="button"
        className="pointer button"
        onClick={_ => ReasonReactRouter.push("login")}>
        {"already have an account?"->React.string}
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