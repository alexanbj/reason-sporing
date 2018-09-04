let apiBaseUrl = "https://sporing.posten.no";
let consignmentUrl = id => {j|$apiBaseUrl/sporing.json?q=$id|j};

type recipientHandlingAddress = {
  postalCode: string,
  city: string,
};

type event = {
  city: string,
  description: string,
  displayDate: string,
  displayTime: string,
  /* TODO: Is this an unique id or something else? */
  unitId: string,
};

type package = {
  dateOfReturn: string,
  statusDescription: string,
  productName: string,
  eventSet: array(event),
};

type consignment_ok = {
  consignmentId: string,
  senderName: string,
  recipientHandlingAddress,
  packageSet: array(package),
  totalVolumeInDm3: float,
  totalWeightInKgs: float,
};

/* Since we have a variant type consignment we flatten the error object from the api*/
type consignment_error = {
  code: int,
  message: string,
};

type consignment =
  | ConsignmentOk(consignment_ok)
  | ConsignmentError(consignment_error);

type consignmentSet = {consignmentSet: array(consignment)};

module Decode = {
  let event = json: event =>
    Json.Decode.{
      city: json |> field("city", string),
      description: json |> field("description", string),
      displayDate: json |> field("displayDate", string),
      displayTime: json |> field("displayTime", string),
      unitId: json |> field("unitId", string),
    };

  let package = json: package =>
    Json.Decode.{
      dateOfReturn: json |> field("dateOfReturn", string),
      productName: json |> field("productName", string),
      statusDescription: json |> field("statusDescription", string),
      eventSet: json |> field("eventSet", array(event)),
    };

  let recipientHandlingAddress = json: recipientHandlingAddress =>
    Json.Decode.{
      postalCode: json |> field("postalCode", string),
      city: json |> field("city", string),
    };

  let consignment_error = json: consignment_error =>
    Json.Decode.{
      code: json |> field("code", int),
      message: json |> field("message", string),
    };

  let consignment = json: consignment => {
    /* We check if there is an error field when decoding the json to determine the correct variant */
    let errorMaybe =
      Json.Decode.(json |> optional(field("error", consignment_error)));

    switch (errorMaybe) {
    | Some(consignmentError) => ConsignmentError(consignmentError)
    | None =>
      ConsignmentOk(
        Json.Decode.{
          consignmentId: json |> field("consignmentId", string),
          senderName: json |> field("senderName", string),
          packageSet: json |> field("packageSet", array(package)),
          recipientHandlingAddress:
            json
            |> field("recipientHandlingAddress", recipientHandlingAddress),
          totalVolumeInDm3: json |> field("totalVolumeInDm3", float),
          totalWeightInKgs: json |> field("totalWeightInKgs", float),
        },
      )
    };
  };

  let consignments = json: array(consignment) =>
    Json.Decode.(json |> array(consignment));

  let consignmentSet = json: consignmentSet =>
    Json.Decode.{
      consignmentSet: json |> field("consignmentSet", consignments),
    };
};

/**
 * Fetch by id, and decode the response before calling the callback
 */
let fetchConsignment = (id, callback) =>
  Js.Promise.(
    Fetch.fetch(consignmentUrl(id))
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Decode.consignmentSet
         |> (consignmentSet => callback(consignmentSet))
         |> resolve
       )
    /* TODO: Better error handling here
     * Do we want two levels of errors, one for the fetches and one for the consignments?
     */
    /* |> catch(_err => Js.Promise.resolve()) */
    |> ignore
  );