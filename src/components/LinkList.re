open ReasonUrql;
open Hooks;
[@bs.val] external parseInt_: (string, int) => int = "parseInt";

/** parseInt with an assumed radix of 10 */
let parseInt = string => parseInt_(string, 10);
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
// let parseInt: string => int = [%raw {| x => {
//   const v = parseInt(x, 10);
//   return isNaN(v) ? 0 : v;
// } |}];
[@react.component]
let make = (~path=ReasonReactRouter.useUrl().path) => {
// let (path, setPath) = React.useState(()=>path)
  Js.log2("path", path);

  // Get the first string in the list and check if it exists with `Belt.List.head`
  // Belt.List.head xs returns None if xs is the empty list, otherwise it returns Some value where value is the first element in the list.
  // see:https://bucklescript.github.io/bucklescript/api/Belt.List.html#VALheadExn

  let pageWithArg = path => path->List.nth(1)->int_of_string;
  //   let test = path->List.nth(1)->Belt.Int.fromString->Belt.Option.getWithDefault(0);
  // Js.log2("Belt.Int.fromString", test);
  let isNewPage = path->Belt.List.has("new", (===)) == true;
  isNewPage ? Js.log2("page-var", pageWithArg(path)) : ();
  Js.log2("isNewPage", isNewPage);
  // !isNewPage ? ReasonReactRouter.replace("/new/1") : ();

  let skip = isNewPage ? (pageWithArg(path) - 1) * 10 : 0;
  // let skip = isNewPage ? (Belt.Int.fromString(Belt.List.tailExn(path)) - 1) * 10 : 0;
  let pageIndex = skip;
  Js.log2("skip", skip);
  Js.log2("page-var", skip);

  let first = isNewPage ? 10 : 100;
  Js.log2("first", first);

  let orderBy = isNewPage ? `createdAt_DESC : `createdAt_DESC;
  Js.log2("orderBy", orderBy);

  // let firstPL = (isNewPage ? 10 : 100)->float_of_int;
  // Js.log2("firstPL", firstPL);

  // let skipPL = (isNewPage ? (pageWithArg(path) - 1) * 10 : 0)->float_of_int;
  // Js.log2("skipPL", skipPL);

  // let orderByPL = isNewPage ? "createdAt_DESC" : "";
  // Js.log2("orderByPL", orderByPL);
  // let payload =
  //   React.useMemo1(
  //     () => {
  //       let variables = Js.Dict.empty();
  //       Js.Dict.set(variables, "skip", Js.Json.number(skipPL));
  //       Js.Dict.set(variables, "first", Js.Json.number(firstPL));
  //       Js.Dict.set(variables, "orderBy", Js.Json.string(orderByPL));
  //       Js.Json.object_(variables);
  //     },
  //     [|path|],
  //   );
  // Js.log2("payload", payload);

  let request = FEED_QUERY.make(~skip, ~first, ~orderBy, ());

  let ({response}, _) = useQuery(~request, ());
  switch (response) {
  | Data(data) =>
    Js.log2("DATA", data);
    let linksToRender = data##feed##links->LinkDecoded.decodeLinks;
    let links =
      linksToRender->Belt.Array.mapWithIndex((index, link) =>
        <Link key={link.id} link index={pageIndex + index} />
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