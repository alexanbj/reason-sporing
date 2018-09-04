module Styles = {
  open Css;

  let hero =
    style([
      padding2(rem(9.0), rem(1.5)),
      backgroundImage(url("/hero_pattern.svg")),
    ]);
};

let component = ReasonReact.statelessComponent("Hero");

let make = children => {
  ...component,
  render: _self => <div className=Styles.hero> ...children </div>,
};