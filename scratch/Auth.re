[@react.component]
let make = () => {
  let (isLogin, setIsLogin) = React.useState(() => true);

  React.useEffect(() => {
    let token = Token.getToken();
    switch (token) {
    | Some(_token) => setIsLogin(_ => true)
    | None => setIsLogin(_ => false)
    };
    None;
  });

  <>
  {isLogin ? <LoginPage2 /> : <SignUp />}
  <button
        type_="button"
        className="pointer button"
        // disabled={state.fetching}
        onClick={_ => setIsLogin(isLogin => !isLogin)}>
        {isLogin
           ? "need to create an account?"->React.string
           : "already have an account?"->React.string}
      </button>
  </>
};