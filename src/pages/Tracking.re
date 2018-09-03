/* The new stdlib additions */
open Belt;

type parcel = array(ConsignmentData.consignment);

type state =
  | Loading
  | Error
  | Loaded(array(ConsignmentData.consignment));

type action =
  | ParcelFetch
  | ParcelFetched(array(ConsignmentData.consignment))
  | ParcelFailedToFetch;

/* module Decode = {
     let dogs = json: array(parcel) =>
       Json.Decode.(
         json |> field("message", array(string)) |> Array.map(_, dog => dog)
       );
   }; */

let component = ReasonReact.reducerComponent("Tracking");

let make = _children => {
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
            /* Js.Promise.(
                 Fetch.fetch(
                   "https://sporing.posten.no/sporing.json?q=TESTPACKAGE-AT-PICKUPPOINT",
                 )
                 |> then_(Fetch.Response.json)
                 |> then_(json =>
                      json
                      |> Decode.dogs
                      |> (dogs => self.send(ParcelFetched(dogs)))
                      |> resolve
                    )
                 |> catch(_err =>
                      Js.Promise.resolve(self.send(ParcelFailedToFetch))
                    )
                 |> ignore
               ) */
        ),
      )
    | ParcelFetched(parcel) => ReasonReact.Update(Loaded(parcel))
    | ParcelFailedToFetch => ReasonReact.Update(Error)
    },
  didMount: self => self.send(ParcelFetch),
  render: _self =>
    <Container>
      <h1> {ReasonReact.string("Sporing")} </h1>
      <ShipmentNotFound />
    </Container>,
};