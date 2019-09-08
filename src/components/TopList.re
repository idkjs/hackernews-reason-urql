open ReasonUrql;
open Hooks;
type link = ReasonHn.Types.Feed.link;
type sort =
  | Asc
  | Desc;
let sortLinks = (~links: array(link), sort) =>
  switch (sort) {
  | Asc =>
    List.sort(
      (a: link, b: link) => a.votes->Array.length - b.votes->Array.length,
      Belt.List.fromArray(links),
    )
  | Desc =>
    List.sort(
      (a: link, b: link) => b.votes->Array.length - a.votes->Array.length,
      Belt.List.fromArray(links),
    )
  };
[@react.component]
let make = (~path=ReasonReactRouter.useUrl().path) => {
  // let (count, setCount) = React.useState(() => 0);
  let (links, setLinks) = React.useState(() => [||]);
  let request = Queries.FEED_QUERY.make(~first=10,());
  // Js.log2("path", path);
  let ({response}, _) = useQuery(~request, ());
  // since we know there is always a variable for the page # because of App.re routers redirect, we can do this.

  React.useEffect1(
    () => {
      switch (response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) => ()
      | Data(resp) =>
        let linksToRender =
          ReasonHn.Types.Feed.decodeLinks(resp##feed##links);
        let linksToRender =
          Sorting.sortLinks(~links=linksToRender, Desc)->Belt.List.toArray;
        let links =
          linksToRender->Belt.Array.mapWithIndex((index, link) =>
            <Link key={link.id} link index />
          );
        ();
        setLinks(_ => links);
      };

      None;
    },
    [|response|] // Here we are listing dependency on which component will be re-rendered.
  );
  <>
    <div> {links |> React.array} </div>
  </>;
};