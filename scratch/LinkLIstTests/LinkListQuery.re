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
let toJson =
  json =>
    json
    ->Js.Json.stringifyAny
    ->Belt.Option.getExn
    ->Js.Json.parseExn;
[@react.component]
let make = (~path=ReasonReactRouter.useUrl().path) => {
  let (count, setCount) = React.useState(() => 0);
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
      <LinkForQuery
        key={
          link##id;
        }
        link
        index={pageIndex + index}
      />
    )
    ->React.array;
  let request = FEED_QUERY.make(~skip, ~first, ~orderBy, ());
  let variables = request##variables;
  let query = request##query;
  let request2={"query": query, "variables": variables, "parse": x => x}
  // let ({response}, _) = useQuery(~request, ());
  // let ({response}, _) =
  //   useQuery(
  //     ~request={"query": query, "variables": variables, "parse": x => x},
  //     // ~pause=true,
  //     (),
  //   );
  let nextPage =
    React.useCallback1(
      () =>
        switch (page <= count / 10) {
          | true => {
            let page = "/new/" ++ (page + 1)->string_of_int;
            ReasonReactRouter.push(page);
          }
            | false => {
              let page = "/new/" ++ (page)->string_of_int;
              ReasonReactRouter.push(page);
            }
          // }
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
  let renderUi = (~links) => {
    <>
      <div> links </div>
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
  // React.useEffect1(
  //   () => {
      // switch (response) {
      // | Fetching => ()
      // | NotFound => ()
      // | Error(_e) => ()
      // | Data(data) =>
          // let data = data->Utils.jsFromJSON;
          // let links = data##feed##links;
          // let count = data##feed##count;

      //     let links = links->linkList;
      //     let _ = renderUi(~links, ~count);
      // };

  //     None;
  //   },
  //   [|response|] // Here we are listing dependency on which component will be re-rendered.
  // );

  // <Query request>
  //   ...{({response}) =>
  //     <main>
  //       {switch (response) {
  //        | Data(data) =>
  //          let links = data##feed##links;
  //          let count = data##feed##count;

  //          let links = links->linkList;
  //          renderUi(~links, ~count);
  //        //  <>
  //        //    <div> links </div>
  //        //    <div className="flex ml4 mv3 gray">
  //        //      <div className="pointer mr2" onClick={_ => previousPage()}>
  //        //        "Previous"->React.string
  //        //      </div>
  //        //      <div className="pointer" onClick={_ => nextPage()}>
  //        //        "Next"->React.string
  //        //      </div>
  //        //    </div>
  //        //  </>;
  //        //  <div> links </div>;
  //        | Fetching => <div> "Loading"->React.string </div>
  //        | Error(_e) => <div> "Error!"->React.string </div>
  //        | NotFound => <div> "Not Found"->React.string </div>
  //        }}
  //     </main>
  //   }
  // </Query>;
  <Query request=request2>
    ...{({response}) =>
      <main>
        {switch (response) {
         | Data(data) =>
          //  let links = data##feed##links;
          //  let count = data##feed##count;
          let data = data->Utils.jsFromJSON;
          let links = data##feed##links;
          let count = data##feed##count;
          setCount(_=>count);
          let links = links->linkList;
          //  renderUi(~links, ~count);
           renderUi(~links);
         //  <>
         //    <div> links </div>
         //    <div className="flex ml4 mv3 gray">
         //      <div className="pointer mr2" onClick={_ => previousPage()}>
         //        "Previous"->React.string
         //      </div>
         //      <div className="pointer" onClick={_ => nextPage()}>
         //        "Next"->React.string
         //      </div>
         //    </div>
         //  </>;
         //  <div> links </div>;
         | Fetching => <div> "Loading"->React.string </div>
         | Error(_e) => <div> "Error!"->React.string </div>
         | NotFound => <div> "Not Found"->React.string </div>
         }}
      </main>
    }
  </Query>;
  // <>
  //   <div> {links |> React.array} </div>
  //   <div className="flex ml4 mv3 gray">
  //     <div className="pointer mr2" onClick={_ => previousPage()}>
  //       "Previous"->React.string
  //     </div>
  //     <div className="pointer" onClick={_ => nextPage()}>
  //       "Next"->React.string
  //     </div>
  //   </div>
  // </>;
};