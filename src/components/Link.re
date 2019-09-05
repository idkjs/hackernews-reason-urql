open ReasonUrql;
// open Hooks;

module VOTE_MUTATION = [%graphql
  {|
    mutation VoteMutation($linkId: ID!) {
    vote(linkId: $linkId) {
      link {
        id
        votes {
          id
          user {
            id
          }
        }
      }
    }
  }
|}
];
// let isFetching =
//   fun
//   | UrqlTypes.Fetching => true
//   | _ => false;

[@react.component]
let make = (~link: LinkDecoded.link, ~index) => {
  // let (error, setError) = React.useState(() => None);
  let (_, executeVoteMutation) =
    Hooks.useMutation(~request=VOTE_MUTATION.make(~linkId=link.id, ()));
  // let (voteResponse, executeMutation) =
  //   Hooks.useMutation(~request=VOTE_MUTATION.make(~linkId=link.id, ()));
  // let (state, executeMutation) = Hooks.useMutation(VOTE_MUTATION);
  // let upvote = React.useCallback(() => {}, [||]);
  // let upvote = e => {
  //   ReactEvent.Mouse.preventDefault(e);
  //   executeMutation() |> ignore;
  // };
  // React.useEffect1(
  //   () => {
  //     switch (voteResponse.response) {
  //     | Fetching => ()
  //     | NotFound => ()
  //     | Error(_e) => setError(_ => Some({js|Something went wrong|js}))
  //     | Data(resp) => Js.log2("VOTED", resp)
  //     };

  //     None;
  //   },
  //   [|voteResponse.response|] // Here we are listing dependency on which component will be re-rendered.
  // );
  <div className="flex mt2 items-start">
  // {switch (error) {
  // | Some(error) => <div className="ml1 gray f11"> error->React.string </div>
  // | None => <div className="ml1 gray f11"> "no-error"->React.string </div>
  // }}
    <div className="flex items-center">
      <span className="gray">
        {string_of_int(index + 1) ++ "." |> React.string}
      </span>
      {Token.isLoggedIn()
         ? <div
             className="ml1 gray f11"
             onClick={_ => executeVoteMutation() |> ignore}>
             {{js|▲|js} |> React.string}
           </div>
         : React.null}
    </div>
    <div className="ml1">
      <div>
        {link.description ++ " (" ++ link.url ++ ") " |> React.string}
      </div>
      <div className="f6 lh-copy gray">
        {string_of_int(Array.length(link.votes))
         ++ " votes | by "
         |> React.string}
        {link.postedBy
         ->Belt.Option.map(postedBy => postedBy.name->React.string)
         ->Belt.Option.getWithDefault("Unknown "->React.string)}
        {Dates.timeDifferenceForDate(link.createdAt)}
      </div>
    </div>
  </div>;
};