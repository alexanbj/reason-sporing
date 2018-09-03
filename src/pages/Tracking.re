let component = ReasonReact.statelessComponent("Tracking");

let make = _children => {
  ...component,
  render: _self =>
    <Container>
      <h1> {ReasonReact.string("Sporing")} </h1>
      <ShipmentNotFound />
    </Container>,
};