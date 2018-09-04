type state = string;

let component = ReasonReact.reducerComponent("TrackingForm");

let handleSubmit = (event, self) => {
  event->ReactEvent.Form.preventDefault;
  let id = self.ReasonReact.state;
  ReasonReact.Router.push(Route.routeToUrl(Route.Tracking(Some(id))));
};

let make = _children => {
  ...component,
  initialState: () => "TESTPACKAGE-AT-PICKUPPOINT",
  /* State transitions */
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: self =>
    <form onSubmit={self.handle(handleSubmit)}>
      <Input
        value={self.state}
        ariaLabel="Sporing på referanse-, sendings- eller kollinummer"
        placeholder="Sporing på referanse-, sendings- eller kollinummer"
        onChange={event => self.send(event->ReactEvent.Form.target##value)}
      />
      <Button type_="submit"> {ReasonReact.string("Søk")} </Button>
    </form>,
};