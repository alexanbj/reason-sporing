type state = string;

let component = ReasonReact.reducerComponent("TrackingForm");

let handleSubmit = (event, _self) => {
  event->ReactEvent.Form.preventDefault;
  ReasonReact.Router.push(Route.routeToUrl(Route.Tracking));
};

let make = _children => {
  ...component,
  initialState: () => "",
  /* State transitions */
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: self =>
    <form onSubmit={self.handle(handleSubmit)}>
      <Input
        value={self.state}
        autoFocus=true
        onChange={event => event->ReactEvent.Form.target##value}
      />
    </form>,
};