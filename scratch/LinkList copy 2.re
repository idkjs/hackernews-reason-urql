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
let make = () => {
  // Set the `ReasonReactRouter`'s `path` list to a variable.
  let path = ReasonReactRouter.useUrl().path;
  Js.log2("path", path);
  let testPageTail = path->Belt.List.tail;
  Js.log2("testPage_tail", Some(testPageTail));
  let testPageHead = path->Belt.List.head;
  // this logs as an unexecuted function because it missing an arg shown in the next version.
  let testPageHasBad = path->Belt.List.has("new");
  let testPageHas = path->Belt.List.has("new", (===)) == true;
  let isHeadNew =
    switch (testPageHead) {
    | Some(head) => head == "new"
    | None => false
    };
  // https://bucklescript.github.io/bucklescript/api/Belt.List.html#VALheadExn
  Js.log2("testPage_head", Some(testPageHead));
  Js.log2("testPageTail", Some(testPageTail));
  Js.log2("testPage_head", testPageHead);
  Js.log2("testPageTail", testPageTail);
  Js.log2("testPageHas", testPageHas);
  Js.log2("testPageHasBad", testPageHasBad);
  Js.log2("isHeadNew", isHeadNew);
  let _ = Belt.List.has(path, "new", (==)) == true |> Js.log;
  let _ = Belt.List.has([1, 2, 3], 2, (==)) == true |> Js.log;
  let _ = Belt.List.has([1, 2, 3], 4, (==)) == false |> Js.log;
  let _ =
    Belt.List.has([(-1), (-2), (-3)], 2, (a, b) => abs(a) == abs(b))
    == true
    |> Js.log;

  // Get the first string in the list and check if it exists with `Belt.List.head`
  // Belt.List.head xs returns None if xs is the empty list, otherwise it returns Some value where value is the first element in the list.
  // Then we convert it to a boolean to return true there is something there and false if not.
  // let isNewPage = path->Belt.List.head->Belt.Option.isSome;
  let page = list => list->List.nth(1)->int_of_string;
  // let testNewPage = path->Belt.List.head;
  // let testPath =
  //   switch (path) {
  //   | [] => None
  //   | [a, ..._] => Some(a)
  //   };
  // // let testPage = path->Belt.List.tail;
  // let testPath =
  //   switch (testPath) {
  //   | None => ""
  //   | Some(a) => a
  //   };
  // // Js.log2("testPage", Some(testPage));
  // // Js.log2("testNewPage", Some(testNewPage));
  // Js.log2("testNewPath", testPath);

  // let checkNewPage = path => {
  //   let valueOrNot = path->Belt.List.head->Belt.Option.isSome;
  //   valueOrNot
  //     ? {
  //       let value = List.hd(path);
  //       Js.log2("value", value);
  //       value == "new";
  //     }
  //     : false;
  // };
  // // Js.log(isNewPage(path));
  // let isNewPage = checkNewPage(path);
  // Js.log2("isNewPage", checkNewPage(path));
  // if `isNewPage` comes back true, get the `id` by passing path to page()
  // open ReasonHn.Types;
  // let payload1 =
  //   payloadToJs({
  //     skip: isNewPage ? (page(path) - 1) * 10 : 0,
  //     first: isNewPage ? 10 : 100,
  //     orderBy: isNewPage ? "createdAt_DESC" : "",
  //   });
  // Js.log2("payload1", payload1);
  // let skip = (isNewPage ? (page(path) - 1) * 10 : 0)->float_of_int;
  // Js.log2("skip", skip);
  // let first = (isNewPage ? 10 : 100)->float_of_int;
  // Js.log2("first", first);
  // let orderBy = isNewPage ? "createdAt_DESC" : "";
  // Js.log2("orderBy", orderBy);
  // let payload =
  //   React.useMemo1(
  //     () => {
  //       let variables = Js.Dict.empty();
  //       Js.Dict.set(variables, "skip", Js.Json.number(skip));
  //       Js.Dict.set(variables, "first", Js.Json.number(first));
  //       Js.Dict.set(variables, "orderBy", Js.Json.string(orderBy));
  //       Js.Json.object_(variables);
  //     },
  //     [|path|],
  //   );
  // let payloadTemplate =
  //   React.useMemo1(
  //     () => {
  //       let variables = Js.Dict.empty();
  //       Js.Dict.set(variables, "key", Js.Json.string(id));
  //       Js.Json.object_(variables);
  //     },
  //     [|id|],
  //   );

  // let (_, executeTreatMutation) =
  //   Hooks.useMutation(
  //     ~request={
  //       "query": Mutations.treatDog,
  //       "variables": payload,
  //       "parse": x => x,
  //     },
  //   );
  // let isNewPage = ReasonReactRouter.useUrl().path->List.hd == "new";
  // Js.log2("isNewPage", isNewPage);
  let request = FEED_QUERY.make();
  // let ({response}, _) =
  //   useQuery(
  //     ~request={
  //       "query": FEED_QUERY.make()##query,
  //       "variables": payload,
  //       "parse": x => x,
  //     },
  //     (),
  //   );
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