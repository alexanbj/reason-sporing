module Styles = {
  open Css;

  let input =
    style([
      border(px(1), solid, rgb(251, 182, 182)),
      padding(rem(1.0)),
      color(Theme.textColor),
      fontSize(rem(1.0)),
      hover([boxShadow(~y=px(18), ~blur=px(56), rgba(0, 0, 0, 0.04))]),
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