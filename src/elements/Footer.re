module Styles = {
  open Css;

  let footer = style([paddingTop(px(30)), paddingBottom(px(30))]);
};

let component = ReasonReact.statelessComponent("Footer");

let make = _children => {
  ...component,
  render: _self =>
    <footer className=Styles.footer>
      <Container>
        <p>
          <small>
            {ReasonReact.string("Powered by ")}
            <A href="https://reasonml.github.io/">
              {ReasonReact.string("Reason.")}
            </A>
          </small>
        </p>
        <p> <small> {ReasonReact.string("Made by alexanbj.")} </small> </p>
      </Container>
    </footer>,
};