module Styles = {
  open Css;

  let heading = style([textAlign(center)]);

  let img =
    style([display(block), margin2(px(30), auto), width(pct(50.))]);
};

let component = ReasonReact.statelessComponent("ConsignmentInfo");

let make = (~consignment: ConsignmentData.consignmentSet, _children) => {
  ...component,
  render: _self =>
    <div>
      {ReasonReact.string("Sendingsnummer:")}
      <span>
        {ReasonReact.string(consignment.consignmentSet[0].consignmentId)}
      </span>
    </div>,
};