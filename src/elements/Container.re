module Styles = {
  open Css;

  let container =
    style([
      maxWidth(px(Theme.containerPixelWidth)),
      marginLeft(auto),
      marginRight(auto),
    ]);
};

let component = ReasonReact.statelessComponent("Container");

let make = children => {
  ...component,
  render: _self => <div className=Styles.container> ...children </div>,
};