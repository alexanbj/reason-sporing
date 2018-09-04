module Styles = {
  open Css;

  let button =
    style([
      textTransform(uppercase),
      padding2(rem(0.5), rem(1.)),
      backgroundColor(Theme.primaryColor),
      color(white),
      fontWeight(500),
      fontSize(rem(0.9)),
      borderStyle(none),
      cursor(`pointer),
      unsafe("WebkitAppearance", "none"),
      boxShadows([
        boxShadow(~y=px(1), ~blur=px(5), rgba(0, 0, 0, 0.2)),
        boxShadow(~y=px(2), ~blur=px(2), rgba(0, 0, 0, 0.14)),
        boxShadow(
          ~y=px(3),
          ~blur=px(1),
          ~spread=px(-2),
          rgba(0, 0, 0, 0.12),
        ),
      ]),
      hover([opacity(0.7)]),
    ]);
};

let component = ReasonReact.statelessComponent("Button");

let make = (~onClick=?, ~type_="button", children) => {
  ...component,
  render: _self =>
    <button className=Styles.button ?onClick type_> ...children </button>,
};