module CurrentUser = {
  type t =
    option({
      .
      "name": option(string),
      "email": string,
      "login": string,
    });

  let user = React.createContext(None: t);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };

  let make = React.Context.provider(user);

  let login = (user: t): option(string) => {
    user->Belt.Option.map(user => user##login);
  };
};