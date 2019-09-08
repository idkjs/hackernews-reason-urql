type link = ReasonHn.Types.Feed.link;
type sort =
  | Asc
  | Desc;
let sortLinks = (~links:array(link), sort) =>
  switch sort {
  | Asc =>
    List.sort((a: link, b: link) => a.votes->Array.length - b.votes->Array.length, Belt.List.fromArray(links))
  | Desc =>
    List.sort((a: link, b: link) => b.votes->Array.length - a.votes->Array.length, Belt.List.fromArray(links))
  };