type vote = {
  id: string,
  user,
}
and user = {id: string};

type postedBy = {
  id: string,
  name: string,
};
type link = {
  id: string,
  createdAt: Js.Date.t,
  description: string,
  url: string,
  votes: array(vote),
  postedBy: option(postedBy),
};
let decodeUser = (json) =>
  Json.Decode.{id: json |> field("id", string)};
let decodePostedBy = (json) =>
  Json.Decode.{
    id: json |> field("id", string),
    name: json |> field("name", string),
  };
let decodeVotes = (json) => {
  Json.Decode.{
    id: json |> field("id", string),
    user: json |> field("user", decodeUser),
  };
};
let decodeLink = (json): link => {
  Json.Decode.{
    id: json |> field("id", string),
    createdAt: json |> field("createdAt", date),
    description: json |> field("description", string),
    url: json |> field("url", string),
    postedBy: json |> optional(field("postedBy", decodePostedBy)),
    votes: json |> field("votes", array(decodeVotes)),
  };
};
let decodeLinks = json => Json.Decode.array(decodeLink, json);
let decodeLinks = (json) =>json->Js.Json.stringifyAny->Belt.Option.getExn->Js.Json.parseExn->decodeLinks