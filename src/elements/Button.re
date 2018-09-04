module Styles = {
  open Css;

  let button =
    style([textTransform(uppercase), padding2(rem(0.5), rem(2.))]);
};

let component = ReasonReact.statelessComponent("Button");

let make = (~onClick=?, ~type_="button", children) => {
  ...component,
  render: _self =>
    <button className=Styles.button ?onClick type_> ...children </button>,
};