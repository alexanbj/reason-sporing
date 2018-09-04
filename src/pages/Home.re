let component = ReasonReact.statelessComponent("HomePage");

let make = _children => {
  ...component,
  render: _self =>
    <>
      <Container>
        <h1> {ReasonReact.string("Spor pakken din")} </h1>
      </Container>
      <Hero> <Container> <TrackingForm /> </Container> </Hero>
    </>,
};