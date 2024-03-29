type action =
  | ToggleRemeber
  | Error(string)
  | SetEmail(string)
  | SetPassword(string);

type state = {
  remember: bool,
  email: string,
  password: string,
  error: option(string),
};

let reducer = (state, action) =>
  switch (action) {
  | ToggleRemeber => {...state, remember: !state.remember}
  | SetEmail(email) => {...state, email}
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
      {remember: false, email: "", password: "", error: None},
    );
  let request =
    Mutations.Login.make(~email=state.email, ~password=state.password, ());
  let (loginResponse, loginMutation) =
    ReasonUrql.Hooks.useMutation(~request);

  let login = (~token) => Token.setToken(token);

/* This is the equivalent of ReactJS's `ComponentDidUpdate` here:https://reactjs.org/docs/react-component.html#componentdidupdate
This will allow the change of the state/props only if certain props are passed or changed to. */

  React.useEffect1(
    () => {
      switch (loginResponse.response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) =>
        dispatch(Error({js|Invalid email and password combination|js}))
      | Data(resp) =>
        resp##login
        ->Belt.Option.map(loginResp => {
            let token = loginResp##token->Belt.Option.getExn;
            login(~token);
            ReasonReactRouter.push("/");
          })
        ->ignore
      };

      None;
    },
    [|loginResponse.response|], // Here we are listing dependency on which component will be re-rendered.
  );

  <div>
    <h4 className="mv3"> "Login"->React.string </h4>
    <div className="flex flex-column">
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
        disabled={isFetching(loginResponse.response)}
        onClick={e => {
              ReactEvent.Mouse.preventDefault(e);
              loginMutation() |> ignore;
            }}>
        {"login"->React.string}
      </button>
      <button
        type_="button"
        className="pointer button"
        onClick={_ => ReasonReactRouter.push("signup")}>
        {"need to create an account?"->React.string}
      </button>
    </div>
  </div>;
};