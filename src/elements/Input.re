module Styles = {
  open Css;

  let input =
    style([
      textDecoration(none),
      color(Theme.primaryColor),
      transition(~duration=15, ~timingFunction=easeIn, "opacity"),
      hover([opacity(0.5)]),
    ]);
};

let component = ReasonReact.statelessComponent("Input");

let make = (~value=?, ~autoFocus=?, ~onChange=?, _children) => {
  ...component,
  render: _self =>
    <input className=Styles.input ?autoFocus ?value ?onChange type_="text" />,
};