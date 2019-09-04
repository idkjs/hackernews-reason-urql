[@react.component]
let make = (~link) => {
    <div>
      <div>
        {link##description ++ " (" ++ link##url ++ ") " |> React.string}
      </div>
    </div>;
};