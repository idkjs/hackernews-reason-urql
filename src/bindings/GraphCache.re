open ReasonUrql;
// include Exchanges;
type cacheExchangeOpts = {
  updates: option(Js.t({.})),
  resolvers: option(Js.t({.})),
  optimistic: option(Js.t({.})),
  keys: option(Js.t({.})),
  schema: option(Js.t({.})),
};

[@bs.module ("@urql/exchange-graphcache","cacheExchange")]
external cacheExchange:(~opts:option(cacheExchangeOpts),unit) => Exchanges.exchange = "cacheExchange";