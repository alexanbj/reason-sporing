module Styles = {
  open Css;

  /* Flex the main element for a sticky footer */
  let appContainer =
    style([minHeight(vh(100.)), display(flexBox), flexDirection(column)]);

  let main = style([flex(1)]);
};

open Route;

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer,
  didMount: self => {
    let watcherID =
      ReasonReact.Router.watchUrl(url =>
        self.send(ChangeRoute(url |> Route.urlToRoute))
      );

    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  initialState: () => {
    route: ReasonReact.Router.dangerouslyGetInitialUrl()->Route.urlToRoute,
  },
  render: self =>
    <div className=Styles.appContainer>
      <Header />
      <main className=Styles.main>
        {
          switch (self.state.route) {
          | Home => <Home />
          | Tracking(id) => <Tracking id />
          | NotFound => <NotFound />
          }
        }
      </main>
      <Footer />
    </div>,
};