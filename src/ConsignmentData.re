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
};

type package = {
  dateOfReturn: string,
  statusDescription: string,
  productName: string,
  eventSet: array(event),
};

type consignment = {
  consignmentId: string,
  senderName: string,
  recipientHandlingAddress,
  packageSet: array(package),
  totalVolumeInDm3: float,
  totalWeightInKgs: float,
};

type shipment =
  | ShipmentFound(consignment)
  | ShipmentNotFound;

type consignmentSet = {consignmentSet: array(consignment)};

module Decode = {
  let event = json: event =>
    Json.Decode.{
      city: json |> field("city", string),
      description: json |> field("description", string),
      displayDate: json |> field("displayDate", string),
      displayTime: json |> field("displayTime", string),
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

  let consignment = json: consignment =>
    Json.Decode.{
      consignmentId: json |> field("consignmentId", string),
      senderName: json |> field("senderName", string),
      packageSet: json |> field("packageSet", array(package)),
      recipientHandlingAddress:
        json |> field("recipientHandlingAddress", recipientHandlingAddress),
      totalVolumeInDm3: json |> field("totalVolumeInDm3", float),
      totalWeightInKgs: json |> field("totalWeightInKgs", float),
    };

  let consignments = json: array(consignment) =>
    Json.Decode.(json |> array(consignment));

  let consignmentSet = json: consignmentSet =>
    Json.Decode.{
      consignmentSet: json |> field("consignmentSet", consignments),
    };
};

let fetchConsignment = (id, callback) =>
  Js.Promise.(
    Fetch.fetch(consignmentUrl(id))
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Decode.consignmentSet
         |> (
           consignments => {
             callback(consignments);
             resolve();
           }
         )
       )
    |> ignore
  );