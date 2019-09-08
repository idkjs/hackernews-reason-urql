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
  let (links, setLinks) = React.useState(() => [||]);
  let request = FEED_SEARCH_QUERY.make(~filter, ());
  let ({response}, executeQuery) =
    useQuery(
      ~request,
      ~pause=true,
      (),
    );
  let search = () => {
    executeQuery |> ignore;
  };
  React.useEffect1(
    () => {
      switch (response) {
      | Fetching => ()
      | NotFound => ()
      | Error(_e) => ()
      | Data(resp) =>
        let linksToRender = ReasonHn.Types.Feed.decodeLinks(resp##feed##links);

        let links =
          linksToRender->Belt.Array.mapWithIndex((index, link) =>
            <Link key={link.id} link index />
          );
        ();
        setLinks(_ => links);
      };

      None;
    },
    [|response|] // Here we are listing dependency on which component will be re-rendered.
  );
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
      <button onClick={_ => search()}> "search"->React.string </button>
    </div>
    <div> {links |> React.array} </div>
  </div>;
};