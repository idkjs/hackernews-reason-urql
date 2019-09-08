  module SignUp = [%graphql
    {|
      mutation SignupMutation($email: String!, $password: String!, $name: String!) {
          signup(email: $email, password: $password, name: $name) {
            token
          }
        }
    |}
  ];

  module Login = [%graphql
    {|
      mutation LoginMutation($email: String!, $password: String!) {
        login(email: $email, password: $password) {
          token
        }
      }
    |}
  ];