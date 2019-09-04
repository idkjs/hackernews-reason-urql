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