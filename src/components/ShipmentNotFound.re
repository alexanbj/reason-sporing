module Styles = {
  open Css;

  let heading = style([textAlign(center)]);

  let img =
    style([display(block), margin2(px(30), auto), width(pct(50.))]);
};

let component = ReasonReact.statelessComponent("ShipmentNotFound");

let make = _children => {
  ...component,
  render: _self =>
    <Container>
      <h2 className=Styles.heading>
        {ReasonReact.string("Beklager, vi fant ingen pakker.")}
      </h2>
      <img className=Styles.img src="/undraw_empty_xct9.svg" ariaHidden=true />
    </Container>,
};