let component = ReasonReact.statelessComponent("HomePage");

let make = _children => {
  ...component,
  render: _self =>
    <Container>
      <h1> {ReasonReact.string("Posten")} </h1>
      <TrackingForm />
    </Container>,
};