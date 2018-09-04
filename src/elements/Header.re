module Styles = {
  open Css;

  let header = style([padding(px(30))]);
};

let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _self =>
    <header className=Styles.header>
      <Container>
        <Link route=Route.Home> {ReasonReact.string("Hjem")} </Link>
      </Container>
    </header>,
};