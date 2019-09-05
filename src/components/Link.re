[@react.component]
let make = (~link:LinkDecoded.link, ~index) => {
  // let upvote = React.useCallback(() => {}, [||]);
  let upvote = Js.log("Upvote");
  let createdAt = link.createdAt;

  <div className="flex mt2 items-start">

      <div className="flex items-center">
        <span className="gray">
          {string_of_int(index + 1) ++ "." |> React.string}
        </span>
        {Token.isLoggedIn()
           ? <div className="ml1 gray f11" onClick={_ev => upvote}>
               {{js|▲|js} |> React.string}
             </div>
           : React.null}
      </div>
      <div className="ml1">
        <div>
          {link.description ++ " (" ++ link.url ++ ") " |> React.string}
        </div>
        <div className="f6 lh-copy gray">
          {string_of_int(Array.length(link.votes)) ++ " votes | by " |> React.string}
          {link.postedBy->Belt.Option.map(postedBy => postedBy.name->React.string)
          ->Belt.Option.getWithDefault("Unknown "->React.string)}
          {Dates.timeDifferenceForDate(link.createdAt)}
        </div>
      </div>
    </div>;
};