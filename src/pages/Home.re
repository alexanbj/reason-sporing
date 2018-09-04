let component = ReasonReact.statelessComponent("HomePage");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Hero> <Container> <TrackingForm /> </Container> </Hero>
      <Container> <h1> {ReasonReact.string("Posten")} </h1> </Container>
    </>,
};