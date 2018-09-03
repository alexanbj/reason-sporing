/** By specifying all routes here, we get complete type safety for our routes! */

type route =
  | Home
  | Tracking
  | NotFound;

/* Go from a route to an URL */
let routeToUrl = route =>
  switch (route) {
  | Home => "/"
  | Tracking => "/sporing"
  | NotFound =>
    raise(Invalid_argument("You're trying to navigate to a not found route"))
  };

/* Go from an URL to a route*/
let urlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [] => Home
  | ["sporing"] => Tracking
  | _ => NotFound
  };