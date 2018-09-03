open Belt;

let apiBaseUrl = "https://sporing.posten.no";
let consignmentUrl = id => {j|$apiBaseUrl/sporing.json?q=$id|j};

type consignment = {
  consignmentId: string,
  totalVolumeInDm3: float,
  totalWeightInKgs: float,
};

module Decode = {
  let consignment = json: consignment =>
    Json.Decode.{
      consignmentId: json |> field("consigmentId", string),
      totalVolumeInDm3: json |> field("totalVolumeInDm3", float),
      totalWeightInKgs: json |> field("totalWeightInKgs", float),
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