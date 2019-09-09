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


[@react.component]
let make = (~link, ~index) => {
  let (_, executeVoteMutation) =
    Hooks.useMutation(~request=VOTE_MUTATION.make(~linkId=link##id, ()));

  <div className="flex mt2 items-start">

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
        {link##description ++ " (" ++ link##url ++ ") " |> React.string}
      </div>
      <div className="f6 lh-copy gray">
        {string_of_int(Array.length(link##votes))
         ++ " votes | by "
         |> React.string}
        // {link##postedBy
        //  ->Belt.Option.map(postedBy => postedBy##name->React.string)
        //  ->Belt.Option.getWithDefault("Unknown "->React.string)}
        // {Dates.timeDifferenceForDate(link##createdAt)}
      </div>
    </div>
  </div>;
};