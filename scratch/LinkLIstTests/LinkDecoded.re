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
type feed = {
  links: array(link),
  count: int,
};
let decodeUser = json => Json.Decode.{id: json |> field("id", string)};
let decodePostedBy = json =>
  Json.Decode.{
    id: json |> field("id", string),
    name: json |> field("name", string),
  };
let decodeVotes = json => {
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

let decodeLinksJson = json => Json.Decode.array(decodeLink, json);
let decodeLinks = json =>
  json
  ->Js.Json.stringifyAny
  ->Belt.Option.getExn
  ->Js.Json.parseExn
  ->decodeLinks;
let decodeLinksJson = json => json->decodeLinksJson;
// =>json->Js.Json.stringifyAny->Belt.Option.getExn->Js.Json.parseExn->decodeLinks
let decodeFeed = json => {
  Json.Decode.{
    links: json |> field("links", array(decodeLink)),
    count: json |> field("count", int),
  };
};

let feedToJs =
  json =>
    json
    ->Js.Json.stringifyAny
    ->Belt.Option.getExn
    ->Js.Json.parseExn
    ->decodeFeed;

let decodeLinksJsonT = json =>
  Json.Decode.at(["feed", "links"], Json.Decode.array(decodeLink), json);

let decodeCount = json =>
  Json.Decode.at(["feed", "count"], Json.Decode.int, json);

module Feed = {
  let decodeFeed = json => {
    Json.Decode.{
      links: json |> field("links", array(decodeLink)),
      count: json |> field("count", int),
    };
  };

  let decode = json => json->decodeFeed;
};