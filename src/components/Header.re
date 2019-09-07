module Link = {
  let handleClick = (href, event) => {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReactRouter.push(href);
  };

  [@react.component]
  let make = (~href, ~className="", ~children) =>
    <a href className onClick={handleClick(href)}> children </a>;
};

[@react.component]
let make = () => {
  let isLoggedIn = Token.isLoggedIn();

  <div className="flex pa1 justify-between nowrap orange">
    <div className="flex flex-fixed black">
      <div className="fw7 mr1"> "Reason Hacker News"->React.string </div>
      <Link href="/" className="ml1 no-underline black">
        "new"->React.string
      </Link>
      <div className="ml1"> "|"->React.string </div>
      <Link href="new/1" className="ml1 no-underline black">
        "top"->React.string
      </Link>
      <div className="ml1"> "|"->React.string </div>
      <Link href="search" className="ml1 no-underline black">
        "search"->React.string
      </Link>
      {isLoggedIn
         ? <div className="flex">
             <div className="ml1"> "|"->React.string </div>
             <Link href="/create" className="ml1 no-underline black">
               "submit"->React.string
             </Link>
           </div>
         : React.null}
    </div>
    <div className="flex flex-fixed">
      {isLoggedIn
         ? <div
             className="ml1 pointer black"
             onClick={_ => {
               Token.deleteToken();
               ReasonReactRouter.push("/");
             }}>
             "logout"->React.string
           </div>
         : <Link href="/login" className="ml1 no-underline black">
             "login"->React.string
           </Link>}
    </div>
  </div>;
};