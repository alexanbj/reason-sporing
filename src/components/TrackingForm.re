module Styles = {
  open Css;

  let form =
    style([
      display(grid),
      /* The column gap in css grid is so nice for spacing between items! */
      gridColumnGap(rem(1.0)),
      unsafe("gridAutoFlow", "column"),
      gridTemplateColumns([auto, minContent]),
    ]);
};
type state = string;

let component = ReasonReact.reducerComponent("TrackingForm");

let handleSubmit = (event, self) => {
  event->ReactEvent.Form.preventDefault;
  let id = self.ReasonReact.state;
  if (String.trim(id) != "") {
    ReasonReact.Router.push(Route.routeToUrl(Route.Tracking(Some(id))));
  };
};

let make = (~initialValue=?, _children) => {
  ...component,
  initialState: () =>
    switch (initialValue) {
    | None => "TESTPACKAGE-AT-PICKUPPOINT"
    | Some(id) => id
    },
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: self =>
    <form className=Styles.form onSubmit={self.handle(handleSubmit)}>
      <Input
        value={self.state}
        ariaLabel="Sporing på referanse-, sendings- eller kollinummer"
        placeholder="Sporing på referanse-, sendings- eller kollinummer"
        onChange={event => self.send(event->ReactEvent.Form.target##value)}
      />
      <Button type_="submit"> {ReasonReact.string("Spor")} </Button>
    </form>,
};