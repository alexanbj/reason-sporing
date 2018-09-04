type parcel = ConsignmentData.consignmentSet;

type state =
  | Loading
  | Error
  | Loaded(ConsignmentData.consignmentSet);

type action =
  | ParcelFetch
  | ParcelFetched(ConsignmentData.consignmentSet)
  | ParcelFailedToFetch;

type retainedProps = {id: option(string)};

let component = ReasonReact.reducerComponentWithRetainedProps("Tracking");

let make = (~id: option(string), _children) => {
  ...component,
  initialState: () => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | ParcelFetch =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            ConsignmentData.fetchConsignment(id, payload =>
              self.send(ParcelFetched(payload))
            )
        ),
      )
    | ParcelFetched(parcel) => ReasonReact.Update(Loaded(parcel))
    | ParcelFailedToFetch => ReasonReact.Update(Error)
    },
  didMount: self => self.send(ParcelFetch),
  retainedProps: {
    id: id,
  },
  didUpdate: ({oldSelf, newSelf: self}) =>
    if (oldSelf.retainedProps.id !== self.retainedProps.id) {
      self.send(ParcelFetch);
    },
  render: self =>
    <Container>
      <h1> {ReasonReact.string("Sporing")} </h1>
      <TrackingForm />
      {
        switch (id, self.state) {
        | (None, _) => <div> {ReasonReact.string("Load packages")} </div>
        | (_, Loading) => <CircularSpinner />
        | (_, Loaded(data)) => <ConsignmentInfo consignment=data />
        | _ => <ShipmentNotFound />
        }
      }
    </Container>,
};