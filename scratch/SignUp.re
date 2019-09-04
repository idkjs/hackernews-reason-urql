open ReasonUrql;
open Client;

[@react.component]
let make = () => {
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  let (name, setName) = React.useState(() => "");
  let request = Mutations.SignUp.make(~email, ~password, ~name, ());

  let handle = (cb, event) => {
    let value = ReactEvent.Form.target(event)##value;
    cb(_ => value);
  };
  let (state, executeMutation) = Hooks.useMutation(~request);
  let executeMutation = () => {
    executeMutation() |> ignore;
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
    ReasonReactRouter.push("/");
  };

  <div>
    <h4 className="mv3"> "Login"->React.string </h4>
    <div className="flex flex-column">
      <input
        value=name
        onChange={handle(setName)}
        type_="text"
        placeholder="Your name"
      />
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
      <button
        type_="button"
        className="pointer mr2 button"
        disabled={state.fetching}
        onChange={_e => executeMutation() |> ignore}>
        "signup"->React.string
      </button>
    </div>
  </div>;
};