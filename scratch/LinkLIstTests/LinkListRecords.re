open ReasonUrql;
open Hooks;
open ReasonHn.Types.Feed
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
  let (links, setLinks) = React.useState(() => None);

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

  let linkList = switch (links) {
    |Some(links)=> Belt.Array.mapWithIndex(links, (index, link) =>
      <LinkR
        key={
          link.id;
        }
        link
        index={pageIndex + index}
      />
    )
    | None => [||]
  };

  let feedQuery = FEED_QUERY.make(~skip, ~first, ~orderBy, ());
  let variables = feedQuery##variables;
  let query = feedQuery##query;
  let request = {"query": query, "variables": variables, "parse": x => x};
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
  let renderUi = () => {
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
  React.useEffect1(
    () => {
      switch (response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) => ()
      | Data(data) =>

        let data:t = decode(data);
        let {links, count} = data.feed;
        // let links = data##feed##links;
        // let count = data##feed##count;
        setCount(_ => count);
        setLinks(_ => Some(links));
      };

      None;
    },
    [|response|] // Here we are listing dependency on which component will be re-rendered.
  );
  renderUi();
};