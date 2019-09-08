type vote = {id: string};

type tweet = {
  id: string,
  text: string,
  votes: array(vote),
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
          {string_of_int(Array.length(tweet.votes))
           ++ " votes | by "
           |> React.string}
        </div>
        <div className="f6 lh-copy gray">
          {string_of_int(voteCount(tweet))
           ++ " votes | by "
           |> React.string}
        </div>
      </div>
    </div>;
  };
};