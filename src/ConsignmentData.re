open Belt;

let apiBaseUrl = "https://sporing.posten.no";
let consignmentUrl = id => {j|$apiBaseUrl/sporing.json?q=$id|j};

type recipientHandlingAddress = {
  postalCode: string,
  city: string,
};

type consignment = {
  consignmentId: string,
  senderName: string,
  recipientHandlingAddress,
  totalVolumeInDm3: float,
  totalWeightInKgs: float,
};

type consignmentSet = {consignmentSet: array(consignment)};

module Decode = {
  let recipientHandlingAddress = json: recipientHandlingAddress =>
    Json.Decode.{
      postalCode: json |> field("postalCode", string),
      city: json |> field("city", string),
    };

  let consignment = json: consignment =>
    Json.Decode.{
      consignmentId: json |> field("consigmentId", string),
      senderName: json |> field("senderName", string),
      recipientHandlingAddress:
        json |> field("recipientHandlingAdress", recipientHandlingAddress),
      totalVolumeInDm3: json |> field("totalVolumeInDm3", float),
      totalWeightInKgs: json |> field("totalWeightInKgs", float),
    };

  let consignmentSet = json: consignmentSet =>
    Json.Decode.{
      consignmentSet:
        json
        |> field("consigmentSet", Json.Decode.(json |> array(consignment))),
    };

  let consignments = json: array(consignment) =>
    Json.Decode.(json |> array(consignment));
};

let fetchConsignment = (id, callback) =>
  Js.Promise.(
    Fetch.fetch(consignmentUrl(id))
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Decode.consignments
         |> (
           consignments => {
             callback(consignments);
             resolve();
           }
         )
       )
    |> ignore
  );