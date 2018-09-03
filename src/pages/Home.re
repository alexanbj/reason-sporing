let component = ReasonReact.statelessComponent("HomePage");

let make = _children => {
  ...component,
  render: _self => <> <h1> {ReasonReact.string("Posten")} </h1> </>,
};