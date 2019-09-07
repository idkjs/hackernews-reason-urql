open ReasonUrql;
open Hooks;

module POST_MUTATION = [%graphql
  {|
    mutation PostMutation($description: String!, $url: String!) {
    post(description: $description, url: $url) {
      id
      createdAt
      url
      description
      postedBy {
        id
        name
      }
      votes {
        id
        user {
          id
        }
      }
    }
  }
|}
];

[@react.component]
let make = () => {
  let (description, setDescription) = React.useState(() => "");
  let (url, setUrl) = React.useState(() => "");
  let request = POST_MUTATION.make(~url, ~description, ());
  let (state, executeMutation) = Hooks.useMutation(~request);

  let handle = (cb, event) => {
    let value = ReactEvent.Form.target(event)##value;
    cb(_ => value);
  };

  let submit = () => {
    executeMutation() |> ignore;
    setDescription(_ => "");
    setUrl(_ => "");
    ReasonReactRouter.push("/");
  };
  let logAll = () => {
    Js.log(url);
    Js.log(description);
  };
  let delay = fn => Js.Global.setTimeout(() => fn(), 3000) |> ignore;

  let createNewLink = () => {
    // Js.log(i);
    setDescription(_ => BsFaker.Hacker.phrase());
    setUrl(_ => BsFaker.Internet.url());
    logAll();
    executeMutation() |> ignore;
  };

  <div>
    <div className="flex flex-column mt3">
      <input
        className="mb2"
        value=description
        onChange={handle(setDescription)}
        type_="text"
        placeholder="A description for the link"
      />
      <input
        className="mb2"
        value=url
        onChange={handle(setUrl)}
        type_="text"
        placeholder="The URL for the link"
      />
    </div>
    <button disabled={state.fetching} onClick={_ => submit()}>
      "Submit"->React.string
    </button>
    <button disabled={state.fetching} onClick={_ => createNewLink()}>
      "createNewLink"->React.string
    </button>
  </div>;
};