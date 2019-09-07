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
//
[@react.component]
let make = () => {
  let route = ReasonReactRouter.useUrl();
  let isNewPage = route.path->List.hd == "new";
  Js.log2("isNewPage", isNewPage);
  Js.log2("route", route);

  // Js.log2("page", page);
  // Js.log2("newPage", newPage);
  // Js.log2("newPage_Path", newPage.path);
  // let page = () => {
  //   let routePath = route.path->List.tl;
  //     Js.log2("routePath", routePath);
  //   // let page = List.nth(routePath, 0)->int_of_string;
  //   // page;
  // };
  // let payload =
  //   variablesToJs({
  //     skip: isNewPage ? (page - 1) * 10 : 0,
  //     first: isNewPage ? 10 : 100,
  //     orderBy: isNewPage ? "createdAt_DESC" : "",
  //   });
  // let payload = {
  //   .
  //   "skip": () => isNewPage ? (page - 1) * 10 : 0,
  //   "first": () => isNewPage ? 10 : 100,
  // };
  // Js.log2("payload", payload);
  /*  If your route response is:

        ```json
      {
        path: ["book", "10", "edit"],
        hash: "author",
        search: "name=Jane"
      }
        ```
        Then pageInt comes from `route.path`'s second item */
  // let pageInt = List.nth(route.path,0);
  // let page = page(props.match.params.page, 10)
  // let payload =
  //   React.useMemo1(
  //     () => {
  //       let variables = Js.Dict.empty();
  //       Js.Dict.set(variables, "key", Js.Json.string(id));
  //       Js.Json.object_(variables);
  //     },
  //     [|id|],
  //   );
  // let variables = React.useMemo(() => ({
  //     skip: isNewPage ? (page - 1) * 10 : 0,
  //     first: isNewPage ? 10 : 100,
  //     orderBy: isNewPage ? 'createdAt_DESC' : null
  //   }), [isNewPage, page])
 
  let request = FEED_QUERY.make();
  let ({response}, _) = useQuery(~request, ());
  switch (response) {
  | Data(data) =>
    // Js.log2("DATA", data##feed##links);
    let linksToRender = LinkDecoded.decodeLinks(data##feed##links);
    let links =
      linksToRender->Belt.Array.mapWithIndex((index, link) =>
        <Link key={link.id} link index />
      );
    <div> {links |> React.array} </div>;
  | Fetching => <div> "Loading"->React.string </div>
  | Error(e) =>
    switch (e.networkError) {
    | Some(_exn) => <div> "Network Error"->React.string </div>
    | None => <div> "No Network Error"->React.string </div>
    }
  | NotFound => <div> "Not Found"->React.string </div>
  };
};