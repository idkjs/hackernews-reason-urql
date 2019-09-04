type action =
  | ToggleRemeber
  | Error(string)
  | ChangeEmail(string)
  | ChangePassword(string);

type state = {
  remember: bool,
  email: string,
  password: string,
  error: option(string),
};

let reducer = (state, action) =>
  switch (action) {
  | ToggleRemeber => {...state, remember: !state.remember}
  | ChangeEmail(email) => {...state, email}
  | ChangePassword(password) => {...state, password}
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

  let login = (~token) =>
    state.remember
      ? Token.setToken(token) : ();

  React.useEffect1(
    () => {
      switch (loginResponse.response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) =>
        dispatch(Error({js|Combinação de email e senha invalidos|js}))
      | Data(resp) =>
        resp##login
        ->Belt.Option.map(loginResp => {
            // let user = loginResp##user;
            let token = loginResp##token->Belt.Option.getExn;
            login(~token);
            ReasonReactRouter.push("/");
          })
        ->ignore
      };

      None;
    },
    [|loginResponse.response|],
  );

  <div className="bg-purple-700 min-h-screen flex flex-col">
    <div className="flex flex-col items-center">
      <div className="bg-white mt-6 p-12">
        <h2 className="font-semibold text-2xl text-center mb-8 px-10">
          {js|Faça login na sua conta|js}->React.string
        </h2>
        {Belt.Option.mapWithDefault(state.error, React.null, err =>
           <div
             className="bg-red-100 border border-red-400 text-red-700 px-4 py-2 rounded mb-8"
             role="alert">
             err->React.string
           </div>
         )}
        <form className="flex flex-col">
          <input
            className="mb-5 p-3 border border-gray-300 rounded"
            type_="text"
            value={state.email}
            onChange={e => {
              let email = ReactEvent.Form.currentTarget(e)##value;
              dispatch(ChangeEmail(email));
            }}
            placeholder={js|Endereço de e-mail|js}
          />
          <input
            className="mb-5 p-3 border border-gray-300 rounded"
            type_="password"
            value={state.password}
            onChange={e => {
              let password = ReactEvent.Form.currentTarget(e)##value;
              dispatch(ChangePassword(password));
            }}
            placeholder="Senha"
          />
          <div className="flex text-xs mb-5">
            <div
              className="flex cursor-pointer"
              onClick={_e => dispatch(ToggleRemeber)}>
              <input
                type_="checkbox"
                className="cursor-pointer my-auto"
                readOnly=true
                checked={state.remember}
              />
              <label className="ml-2 cursor-pointer">
                "Lembrar de mim"->React.string
              </label>
            </div>
            <a className="ml-auto cursor-pointer hover:text-blue-500">
              "Esqueceu sua senha?"->React.string
            </a>
          </div>
          <button
            disabled={isFetching(loginResponse.response)}
            className="font-semibold py-3"
            onClick={e => {
              ReactEvent.Mouse.preventDefault(e);
              loginMutation() |> ignore;
            }}>
            "ENTRAR"->React.string
          </button>
        </form>
      </div>
    </div>
  </div>;
};