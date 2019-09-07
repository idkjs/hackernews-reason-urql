open ReasonUrql;
open Hooks;
module FEED_SEARCH_QUERY = [%graphql
  {|
query FeedSearchQuery($filter: String!) {
    feed(filter: $filter) {
      links {
        id
        url
        description
        createdAt
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
    }
  }
|}
];

[@react.component]
let make = () => {
  let (filter, setFilter) = React.useState(() => "");
  // let (links, setLinks) = React.useState(() => [||]);
  let request = FEED_SEARCH_QUERY.make(~filter, ());
  let (result, executeQuery) = useQuery(~request,~requestPolicy=`NetworkOnly, ~pause=true, ());
  // let search = React.useCallback(() => executeQuery, executeQuery |> ignore);
  let refetch = React.useCallback(() => executeQuery(None));
  // let search = () => {
  //   executeQuery |> ignore;
  // };
  let links =
    switch (result.data) {
    | Some(data) => data##feed##links
    | None => [||]
    };
  let linksToRender = LinkDecoded.decodeLinks(links);

  let links =
    linksToRender->Belt.Array.mapWithIndex((index, link) =>
      <Link key={link.id} link index />
    );
  ();
  <div>
    <div>
        "Search"->React.string
        <input
          type_="text"
          onChange={e => {
            let filter = ReactEvent.Form.currentTarget(e)##value;
            setFilter(filter);
          }}
        />
      </div>
      <button onClick={_e =>refetch()}> "search"->React.string </button>
    <div> {links |> React.array} </div>
  </div>;
};