type parcel = array(ConsignmentData.consignment);

type state =
  | Loading
  | Error
  | Loaded(array(ConsignmentData.consignment));

type action =
  | ParcelFetch
  | ParcelFetched(array(ConsignmentData.consignment))
  | ParcelFailedToFetch;

let component = ReasonReact.reducerComponent("Tracking");

let make = (~id=?, _children) => {
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
  render: self =>
    <Container>
      <h1> {ReasonReact.string("Sporing")} </h1>
      {
        switch (id, self.state) {
        | (None, _) => <div> {ReasonReact.string("Load packages")} </div>
        | (_, Loading) => <CircularSpinner />
        | _ => <ShipmentNotFound />
        }
      }
    </Container>,
};