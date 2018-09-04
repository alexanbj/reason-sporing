module Styles = {
  open Css;

  let status =
    style([
      display(grid),
      gridTemplateColumns([minContent, auto]),
      gridColumnGap(rem(1.)),
      gridRowGap(rem(1.)),
    ]);

  let timestamp = style([color(Theme.secondaryTextColor)]);
};

module Circle = {
  let component = ReasonReact.statelessComponent("StatusCircle");
  let make = _children => {
    ...component,
    render: _self => <svg> <circle cx="12" cy="12" r="12" /> </svg>,
  };
};

let component = ReasonReact.statelessComponent("ConsignmentStatus");

let make = (~consignment: ConsignmentData.consignment_ok, _children) => {
  ...component,
  render: _self =>
    <div>
      <h3> {ReasonReact.string("Status")} </h3>
      <div className=Styles.status>
        {
          consignment.packageSet[0].eventSet
          |> Array.map((event: ConsignmentData.event) =>
               <>
                 <div> {ReasonReact.string("test")} </div>
                 <div>
                   <div> {ReasonReact.string(event.description)} </div>
                   <small className=Styles.timestamp>
                     {
                       ReasonReact.string(
                         event.displayDate ++ " " ++ event.displayTime,
                       )
                     }
                   </small>
                 </div>
               </>
             )
          |> ReasonReact.array
        }
      </div>
    </div>,
};