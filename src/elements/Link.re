/** This is the route aware component for type safe anchors.
    Think React Router's Link component.
    For rendering anchor's that aren't routes, see A.
*/
let component = ReasonReact.statelessComponent("Link");

let handleClick = (href, onClick, event) => {
  switch (onClick) {
  | Some(onClick) => event->onClick
  | _ => ()
  };

  /** TODO: Only do this if the default hasn't been prevented? */
  event->ReactEvent.Mouse.preventDefault;
  ReasonReact.Router.push(href);
};

let make = (~route: Route.route, ~onClick=?, children) => {
  ...component,
  render: _self => {
    let href = Route.routeToUrl(route);
    <A href onClick={handleClick(href, onClick)}> ...children </A>;
  },
};