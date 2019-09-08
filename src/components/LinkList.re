open ReasonUrql;
open Hooks;

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
  let isTop =
    switch (path) {
    | ["top", ..._] => true
    | _ => false
    };
  let skip = (page - 1) * 10;

  let pageIndex = skip;

  let first = 10;

  let orderBy = `createdAt_DESC;

  let request = Queries.FEED_QUERY.make(~skip, ~first, ~orderBy, ());
  let ({response}, _) = useQuery(~request, ());

  let nextPage =
    React.useCallback1(
      () =>
        page <= count / 10
          ? {
            let page = "/new/" ++ (page + 1)->string_of_int;
            ReasonReactRouter.push(page);
          }
          : {
            let page = "/new/" ++ page->string_of_int;
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
  let rankedLinks = Sorting.sortLinks(~links, Desc)->Belt.List.toArray;

  let linksToRender =
    React.useMemo1(
      () => Array.length(links) < 1 ? links : rankedLinks,
      [|links|],
    );
  let linkList =
    links->Belt.Array.mapWithIndex((index, link) =>
      <Link key={link.id} link index={pageIndex + index} />
    );

  // let linksToRender = React.useMemo1(
  //       () => Array.length(links) < 1 ? () :
  //     rankedLinks
  //   }, [links]);

  React.useEffect1(
    () => {
      switch (response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) => ()
      | Data(data) =>
        let links = data##feed##links->ReasonHn.Types.Feed.decodeLinks;

        let links = !isTop ? links : linksToRender;

        // let linksToRender = data##feed##links->ReasonHn.Types.Feed.decodeLinks;
        // let linksToRender = data##feed##links->ReasonHn.Types.Feed.decodeLinks;
        setLinks(_ => links);
        let count = data##feed##count;
        setCount(_ => count);
      };

      None;
    },
    [|response|] // Here we are listing dependency on which component will be re-rendered.
  );
  <>
    <div> linkList->React.array </div>
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