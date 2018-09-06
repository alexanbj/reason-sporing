open Jest;
open ConsignmentData;

let parse = Js.Json.parseExn;

describe("Decode", () => {
  open Expect;
  test("that we can deserialize not found json", () => {
    let notFoundJson =
      {|{
        "consignmentSet": [
          {
            "error": {
              "code": 404,
              "message": "No shipments found"
            }
          }
        ]
      }|}
      ->parse;

    expect(notFoundJson->Decode.consignmentSet) |> toMatchSnapshot;
  });

  test("that we can deserialize shipment found json", () => {
    let json =
      {|{
        "consignmentSet": [
          {
            "consignmentId": "SHIPMENTNUMBER",
            "previousConsignmentId": "",
            "packageSet": [
              {
                "statusDescription": "Sendingen kan hentes p\u00e5 utleveringssted.",
                "descriptions": [

                ],
                "packageNumber": "TESTPACKAGEATPICKUPPOINT",
                "previousPackageNumber": "",
                "productName": "Kliman\u00f8ytral servicepakke",
                "productCode": "1202",
                "brand": "POSTEN",
                "lengthInCm": 41,
                "widthInCm": 38,
                "heightInCm": 29,
                "volumeInDm3": 45.2,
                "weightInKgs": 16.5,
                "pickupCode": "AA11",
                "dateOfReturn": "01.12.2011",
                "senderName": "POSTEN NORGE AS",
                "senderAddress": {
                  "addressLine1": "",
                  "addressLine2": "",
                  "postalCode": "",
                  "city": "",
                  "countryCode": "",
                  "country": ""
                },
                "recipientHandlingAddress": {
                  "addressLine1": "",
                  "addressLine2": "",
                  "postalCode": "1407",
                  "city": "VINTERBRO",
                  "countryCode": "",
                  "country": ""
                },
                "eventSet": [
                  {
                    "description": "Sendingen er ankommet utleveringssted.",
                    "status": "READY_FOR_PICKUP",
                    "recipientSignature": {
                      "name": ""
                    },
                    "unitId": "122608",
                    "unitInformationUrl": "http:\/\/fraktguide.bring.no\/fraktguide\/api\/pickuppoint\/id\/122608",
                    "unitType": "BRING",
                    "postalCode": "2341",
                    "city": "L\u00d8TEN",
                    "countryCode": "NO",
                    "country": "Norway",
                    "dateIso": "2010-10-01T08:30:25+02:00",
                    "displayDate": "01.10.2010",
                    "displayTime": "08:30",
                    "consignmentEvent": false
                  },
                  {
                    "description": "Sendingen er innlevert til terminal og videresendt.",
                    "status": "IN_TRANSIT",
                    "recipientSignature": {
                      "name": ""
                    },
                    "unitId": "032850",
                    "unitType": "BRING",
                    "postalCode": "0024",
                    "city": "OSLO",
                    "countryCode": "NO",
                    "country": "Norway",
                    "dateIso": "2010-09-30T08:27:08+02:00",
                    "displayDate": "30.09.2010",
                    "displayTime": "08:27",
                    "consignmentEvent": false,
                    "definitions": [
                      {
                        "term": "terminal",
                        "explanation": "Brev, pakke eller godsterminal som benyttes til sortering  og omlasting av sendinger som er underveis til mottaker."
                      }
                    ]
                  }
                ]
              }
            ],
            "senderName": "POSTEN NORGE AS",
            "senderAddress": {
              "addressLine1": "",
              "addressLine2": "",
              "postalCode": "",
              "city": "",
              "countryCode": "",
              "country": ""
            },
            "recipientHandlingAddress": {
              "addressLine1": "",
              "addressLine2": "",
              "postalCode": "1407",
              "city": "VINTERBRO",
              "countryCode": "",
              "country": ""
            },
            "senderReference": "",
            "totalWeightInKgs": 16.5,
            "totalVolumeInDm3": 45.2
          }
        ]
      }|}
      ->parse;

    expect(json) |> toMatchSnapshot;
  });
});