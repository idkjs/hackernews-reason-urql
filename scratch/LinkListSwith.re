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

  // since we know there is always a variable for the page # because of App.re routers redirect, we can do this.
  let page = path->Belt.List.tail;
  let _ = Utils.inspect2(page, "page_tail");
  let page = page->Utils.Option.getExn;
  let page2 =
    switch (page) {
    | [_, x, ..._] => int_of_string(x)
    | _ => 0
    };
  let _ = Utils.inspect2(page2, "page2_page_switch");
  let _ = Utils.inspect2(page, "page_getExn");
  let page = page->List.nth(0)->Belt.Int.fromString;
  let _ = Utils.inspect2(page, "page_fromString");
  let page =
    switch (path) {
    | [_, x, ..._] => int_of_string(x)
    | _ => 0
    };
  let _ = Utils.inspect2(page, "page_path_switch");
  let page =
    switch (path) {
    | ["new", x, ..._] => int_of_string(x)
    | _ => 0
    };
  let _ = Utils.inspect2(page, "isNew_page_path_switch");
  // let tail = switch(path->Belt.List.tail){
  //   | Some(tail) => tail|>Utils.inspect(tail)
  //   | None => 10
  // };

  // ->Belt.Int.fromString;
  // Js.log2("Belt.Int.fromString", test);
  let isNewPage = path->Belt.List.has("new", (===)) == true;
  isNewPage ? Js.log2("page-var", pageWithArg(path)) : ();
  Js.log2("isNewPage", isNewPage);
  // !isNewPage ? ReasonReactRouter.replace("/new/1") : ();
// let isNewPage = isNew->Belt.Option.isSome
  let skip = isNewPage ? (pageWithArg(path) - 1) * 10 : 0;
  let skip = isNewPage ? (page - 1) * 10 : 0;
  let skip = (page - 1) * 10;
  // let skip = isNewPage ? (Belt.Int.fromString(Belt.List.tailExn(path)) - 1) * 10 : 0;
  let pageIndex = skip;
  Js.log2("skip", skip);
  Js.log2("page-var", skip);

  let first = isNewPage ? 10 : 100;
  let first = 10;
  Js.log2("first", first);

  let orderBy = isNewPage ? `createdAt_DESC : `createdAt_DESC;
  let orderBy = `createdAt_DESC;
  Js.log2("orderBy", orderBy);


let  nextPage = React.useCallback(() => {
    if (page <= data.feed.count / 10) {
      ReasonReactRouter.push("/new/${page + 1}");
    }
  }, [props.history, data.feed.count, page]);

  let  previousPage = React.useCallback(() => {
    if (page > 1) {
      ReasonReactRouter.push("/new/${page - 1}");
    }
  }, [props.history, page]);

  let request = FEED_QUERY.make(~skip, ~first, ~orderBy, ());
Js.log2("request", request);
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