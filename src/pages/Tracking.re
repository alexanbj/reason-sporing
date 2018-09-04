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
            ConsignmentData.fetchConsignment(
              "TESTPACKAGE-AT-PICKUPPOINT", payload =>
              self.send(ParcelFetched(payload))
            )
        ),
      )
    | ParcelFetched(parcel) => ReasonReact.Update(Loaded(parcel))
    | ParcelFailedToFetch => ReasonReact.Update(Error)
    },
  didMount: self => self.send(ParcelFetch),
  render: _self =>
    <Container>
      <h1> {ReasonReact.string("Sporing")} </h1>
      {
        switch (id) {
        | None => <div> {ReasonReact.string("id")} </div>
        | Some(id) => <ShipmentNotFound />
        }
      }
    </Container>,
};