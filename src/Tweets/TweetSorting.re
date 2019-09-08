type vote = {id: string};

type tweet = {
  id: string,
  text: string,
  votes: array(vote),
};

type sort =
  | Asc
  | Desc;
let sortTweets = (~tweets: array(tweet), sort) =>
  switch (sort) {
  | Asc =>
    List.sort(
      (a: tweet, b: tweet) => a.votes->Array.length - b.votes->Array.length,
      Belt.List.fromArray(tweets),
    )
  | Desc =>
    List.sort(
      (a: tweet, b: tweet) => b.votes->Array.length - a.votes->Array.length,
      Belt.List.fromArray(tweets),
    )
  };
let dummyTweets = [|
  {
    id: "id_1",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_2",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_3",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_4",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_5",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_6",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_7",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_8",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_9",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
  {
    id: "id_10",
    text: "Some insightful tweet",
    votes: [|
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
      {id: "ck0a0ychmjv5b0b09zlz6ps6m"},
    |],
  },
|];

let voteCount = tweet => tweet.votes->Belt.Array.size;

module Tweet = {
  [@react.component]
  let make = (~tweet, ~index) => {
    <div className="flex mt2 items-start">
      <div className="flex items-center">
        <span className="gray">
          {string_of_int(index + 1) ++ "." |> React.string}
        </span>
      </div>
      <div className="ml1">
        <div> {tweet.text |> React.string} </div>
        <div className="f6 lh-copy gray">
          {" votes " ++ string_of_int(voteCount(tweet)) |> React.string}
        </div>
      </div>
    </div>;
  };
};
let renderTweets = (~tweets) =>
  tweets
  ->Belt.Array.mapWithIndex((index, tweet) =>
      <Tweet key={tweet.id} tweet index />
    )
  ->React.array;

[@react.component]
let make = () => {
  let (toggle, setToggle) = React.useState(() => false);
  let (direction, setDirection) = React.useState(() => Asc);
  let sorted = sortTweets(~tweets=dummyTweets, direction)->Belt.List.toArray;
  let handleDirection = ()=>
    direction == Asc ? setDirection(_ => Desc) : setDirection(_ => Asc);
  <div>
    <button onClick={_ => setToggle(_ => !toggle)}>
      "Toggle"->React.string
    </button>
    {toggle ? renderTweets(~tweets=dummyTweets) : React.null}
    <button onClick={_ => handleDirection()}>
      "ToggleSorted"->React.string
    </button>
    {renderTweets(~tweets=sorted)}
  </div>;
};