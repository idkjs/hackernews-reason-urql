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
  </div>;
};