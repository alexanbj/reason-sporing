module Styles = {
  open Css;

  let primaryText =
    style([display(block), fontWeight(500), fontSize(rem(0.8))]);

  let secondaryText = style([display(block), marginBottom(rem(1.5))]);

  let hr =
    style([
      margin2(rem(1.5), zero),
      borderBottom(px(1), solid, rgb(238, 238, 238)),
      border(zero, none, transparent),
    ]);
};

module PrimaryText = {
  let component = ReasonReact.statelessComponent("PrimaryText");
  let make = children => {
    ...component,
    render: _self => <span className=Styles.primaryText> ...children </span>,
  };
};

module SecondaryText = {
  let component = ReasonReact.statelessComponent("SecondaryText");
  let make = children => {
    ...component,
    render: _self => <span className=Styles.secondaryText> ...children </span>,
  };
};

let component = ReasonReact.statelessComponent("ConsignmentInfo");

let make = (~consignment: ConsignmentData.consignment_ok, _children) => {
  ...component,
  render: _self =>
    <div>
      <Card>
        <SecondaryText>
          {consignment.packageSet[0].statusDescription |> ReasonReact.string}
        </SecondaryText>
        <hr className=Styles.hr />
        <PrimaryText> {"Siste hentedato" |> ReasonReact.string} </PrimaryText>
        <SecondaryText>
          {consignment.packageSet[0].dateOfReturn |> ReasonReact.string}
        </SecondaryText>
        <PrimaryText> {"Avsender" |> ReasonReact.string} </PrimaryText>
        <SecondaryText>
          {consignment.senderName |> ReasonReact.string}
        </SecondaryText>
        <PrimaryText> {"Sendingsnummer" |> ReasonReact.string} </PrimaryText>
        <SecondaryText>
          {consignment.consignmentId |> ReasonReact.string}
        </SecondaryText>
        <PrimaryText> {"Vekt" |> ReasonReact.string} </PrimaryText>
        <SecondaryText>
          {
            (consignment.packageSet[0].weightInKgs |> string_of_float)
            ++ " kg"
            |> ReasonReact.string
          }
        </SecondaryText>
      </Card>
      <ConsignmentStatus consignment />
    </div>,
};