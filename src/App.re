module AsyncData = Relude.AsyncData;

[@react.component]
let make = () => {
  let currentUser = Hook.useCurrentUser();
  let route = Route.useRoute();

  switch (currentUser) {
  | Init
  | Loading => React.null
  | Reloading(user)
  | Complete(user) =>
    <>
      <Header user />
      {switch (route) {
       | Settings => <Settings />
       | Login => <Login />
       | Register => <Register />
       | CreateArticle => <Editor />
       | EditArticle(slug) => <Editor slug />
       | Article(slug) => <Article slug />
       | Profile(username) => <Profile viewMode={Profile.Author(username)} />
       | Favorited(username) =>
         <Profile viewMode={Profile.Favorited(username)} />
       | Home => <Home user />
       }}
      <Footer />
    </>
  };
};
