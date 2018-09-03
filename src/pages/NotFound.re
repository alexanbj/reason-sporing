let component = ReasonReact.statelessComponent("NotFoundPage");

let make = _children => {
  ...component,
  render: _self =>
    <Container>
      <h1> {ReasonReact.string("Oops!")} </h1>
      <h2>
        {ReasonReact.string("Ser ikke ut som vi har siden du leter etter.")}
      </h2>
    </Container>,
};