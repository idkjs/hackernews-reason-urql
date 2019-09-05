let timeDifference = (~current:float, ~previous:float) => {
  let milliSecondsPerMinute = 60. *. 1000.;
  let milliSecondsPerHour = milliSecondsPerMinute *. 60.;
  let milliSecondsPerDay = milliSecondsPerHour *. 24.;
  let milliSecondsPerMonth = milliSecondsPerDay *. 30.;
  let milliSecondsPerYear = milliSecondsPerDay *. 365.;

  let elapsed = current -. previous;

  if (elapsed < milliSecondsPerMinute) {
    "less than 1 min ago"->React.string;
  } else if (elapsed < milliSecondsPerHour) {
    (
      (elapsed /. milliSecondsPerMinute)
      |> Js.Math.round
      |> Js.Float.toString
    )
    ++ " min ago"
    |> React.string;
  } else if (elapsed < milliSecondsPerDay) {
    (
      (elapsed /. milliSecondsPerHour)
      |> Js.Math.round
      |> Js.Float.toString
    )
    ++ " h ago"
    |> React.string;
  } else if (elapsed < milliSecondsPerMonth) {
    (
      (elapsed /. milliSecondsPerDay)
      |> Js.Math.round
      |> Js.Float.toString
    )
    ++ " days ago"
    |> React.string;
  } else if (elapsed < milliSecondsPerYear) {
    (
      (elapsed /. milliSecondsPerMonth)
      |> Js.Math.round
      |> Js.Float.toString
    )
    ++ " mo ago"
    |> React.string;
  } else {
    (
      (elapsed /. milliSecondsPerYear)
      |> Js.Math.round
      |> Js.Float.toString
    )
    ++ " years ago"
    |> React.string;
  };
};

let makeDate = date => Js.Date.(date |> getTime);
let timeDifferenceForDate = (createdAt) => {
  let now = Js.Date.now();
  let updated = makeDate(createdAt);
  timeDifference(~current=now, ~previous=updated);
};