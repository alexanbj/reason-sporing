module Styles = {
  open Css;

  let card =
    style([
      padding(px(25)),
      borderRadius(px(6)),
      border(px(1), solid, rgb(232, 232, 232)),
      boxShadow(~y=px(18), ~blur=px(56), rgba(0, 0, 0, 0.04)),
    ]);
};

let component = ReasonReact.statelessComponent("Card");

let make = children => {
  ...component,
  render: _self => <div className=Styles.card> ...children </div>,
};