module type Key = {let key: string;};

module LocalStorage = (K: Key) => {
  open Dom.Storage;
  let key = K.key;
  let get = () => getItem(key, localStorage);
  let set = value => setItem(key, value, localStorage);
  let remove = () => removeItem(key, localStorage);
};

module Token =
  LocalStorage({
    let key = "auth-token";
  });

let getToken = () => Token.get();
let setToken = token => Token.set(token);
let deleteToken = () => Token.remove();

// let isLoggedIn = () => getToken()
//   |> token => {
//        // This will switch to the App screen or Auth screen and this loading screen will be unmounted and thrown away.
//        Js.log2("CHECKING_AUTH_TOKEN", token);
//        switch (token) {
//        | None => false
//        | Some(_token) => true
//        };
//      };
let isLoggedIn = () => Token.get()->Belt.Option.isSome;
let resetStore = () => {
  Token.remove();
};