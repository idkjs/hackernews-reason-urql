open ReasonUrql;
open Hooks;

module FEED_QUERY = [%graphql
  {|
    {feed {
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
  let request = FEED_QUERY.make();
  let ({response}, _) = useQuery(~request, ());
  switch (response) {
  | Data(data) =>
    // Js.log2("DATA", data##feed##links);
    let linksToRender = LinkDecoded.decodeLinks(data##feed##links);
    let links =
      linksToRender->Belt.Array.mapWithIndex((index, link) =>
        <Link key={string_of_int(index)} link index />
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