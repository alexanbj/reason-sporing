module Styles = {
  open Css;

  let input =
    style([
      borderRadius(px(6)),
      border(px(1), solid, rgb(232, 232, 232)),
      padding(rem(1.5)),
      color(Theme.textColor),
      fontSize(rem(1.0)),
    ]);
};

let component = ReasonReact.statelessComponent("Input");

let make = (~value=?, ~ariaLabel, ~onChange=?, ~placeholder=?, _children) => {
  ...component,
  render: _self =>
    <input
      className=Styles.input
      ariaLabel
      ?value
      ?onChange
      ?placeholder
      type_="text"
    />,
};