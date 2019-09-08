open ReasonUrql;
open Hooks;

module FEED_QUERY = [%graphql
  {|
    query FeedQuery($first: Int, $skip: Int, $orderBy: LinkOrderByInput) {
    feed(first: $first, skip: $skip, orderBy: $orderBy) {
      count
      links {
        id
        createdAt
        url
        description
        postedBy {
          id
          name
        }
        votes {
          id
          user {
            id
          }
        }
      }
    }}
|}
];

[@react.component]
let make = (~path=ReasonReactRouter.useUrl().path) => {
  let (count, setCount) = React.useState(() => 0);
  let (links, setLinks) = React.useState(() => [||]);
  // Js.log2("path", path);

  // since we know there is always a variable for the page # because of App.re routers redirect, we can do this.

  let page =
    switch (path) {
    | ["new", x, ..._] => int_of_string(x)
    | _ => 0
    };
  // let _ = Utils.inspect2(page, "isNew_page_path_switch");

  let skip = (page - 1) * 10;

  let pageIndex = skip;

  let first = 10;

  let orderBy = `createdAt_DESC;
  
  let linkList = links =>
    Belt.Array.mapWithIndex(links, (index, link) =>
      <Link key={link.id} link index={pageIndex + index} />
    )
    ->React.array;
  let request = FEED_QUERY.make(~skip, ~first, ~orderBy, ());
  let variables = request##variables;
  let query = request##query;
  // let ({response}, _) = useQuery(~request, ());
  let ({response}, _) =
    useQuery(
      ~request={"query": query, "variables": variables, "parse": x => x},
      // ~pause=true,
      (),
    );
  let nextPage =
    React.useCallback1(
      () =>
        if (page <= count / 10) {
          Js.log2("next_count", count);
          let page = page + 1;
          let page = "/new/" ++ (page + 1)->string_of_int;
          ReasonReactRouter.push(page);
        },
      [|count, page|],
    );
  let previousPage =
    React.useCallback1(
      () =>
        if (page > 1) {
          let page = "/new/" ++ (page - 1)->string_of_int;
          ReasonReactRouter.push(page);
        },
      [|page|],
    );

  React.useEffect1(
    () => {
      switch (response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) => ()
      | Data(data) =>
        let linksToRender = LinkDecoded.decodeLinksJsonT(data);

        let count = LinkDecoded.decodeCount(data);
        setCount(_ => count);
        Js.log2("count", count);

        let links =
          linksToRender->Belt.Array.mapWithIndex((index, link) =>
            <Link key={link.id} link index={pageIndex + index} />
          );
        ();
        setLinks(_ => links);
      };

      None;
    },
    [|response|] // Here we are listing dependency on which component will be re-rendered.
  );

  // switch (response) {
  // | Fetching => ()
  // | NotFound => ()
  // | Error(_e) => ()
  // | Data(data) =>
  //   let linksToRender = LinkDecoded.decodeFeed(data);

  //   let count = LinkDecoded.decodeCount(data);
  //   setCount(_ => count);
  //   Js.log2("count", count);

  //   let links =
  //     linksToRender->Belt.Array.mapWithIndex((index, link) =>
  //       <Link key={link.id} link index={pageIndex + index} />
  //     );
  //   ();
  //   setLinks(_ => links);
  // };
  <>
    <div> {links |> React.array} </div>
    <div className="flex ml4 mv3 gray">
      <div className="pointer mr2" onClick={_ => previousPage()}>
        "Previous"->React.string
      </div>
      <div className="pointer" onClick={_ => nextPage()}>
        "Next"->React.string
      </div>
    </div>
  </>;
};