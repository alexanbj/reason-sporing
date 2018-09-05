/* The different states this component is in */
type state =
  | Loading
  | Error
  | Loaded(ConsignmentData.consignmentSet);

/* The different action types this component dispatches to it self */
type action =
  | ConsignmentFetch
  | ConsignmentFetched(ConsignmentData.consignmentSet)
  | ConsignmentFailedToFetch;

type retainedProps = {id: option(string)};

let component = ReasonReact.reducerComponentWithRetainedProps("Tracking");

let make = (~id: option(string), _children) => {
  ...component,
  initialState: () => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | ConsignmentFetch =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            ConsignmentData.fetchConsignment(id, payload =>
              self.send(ConsignmentFetched(payload))
            )
        ),
      )
    | ConsignmentFetched(data) => ReasonReact.Update(Loaded(data))
    | ConsignmentFailedToFetch => ReasonReact.Update(Error)
    },
  /* On mount we dispatch a fetch */
  didMount: self => self.send(ConsignmentFetch),
  retainedProps: {
    id: id,
  },
  didUpdate: ({oldSelf, newSelf: self}) =>
    if (oldSelf.retainedProps.id !== self.retainedProps.id) {
      self.send(ConsignmentFetch);
    },
  render: self =>
    <Container>
      <h1> {ReasonReact.string("Sporing")} </h1>
      <TrackingForm initialValue=?id />
      {
        switch (self.state) {
        | Loading => <CircularSpinner />
        | Loaded(data) =>
          /* TODO: Get rid of nested switch */
          switch (data.consignmentSet[0]) {
          | ConsignmentData.ConsignmentError(err) when err.code == 404 =>
            <ShipmentNotFound />
          | ConsignmentData.ConsignmentError(err) =>
            <div> {ReasonReact.string(err.message)} </div>
          | ConsignmentData.ConsignmentOk(consignment) =>
            <ConsignmentInfo consignment />
          }
        | _ => <div> {ReasonReact.string("Det oppstod en ukjent feil")} </div>
        }
      }
    </Container>,
};