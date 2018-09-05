module Styles = {
  open Css;

  let statusGrid =
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
      <h3> {"Status" |> ReasonReact.string} </h3>
      <div className=Styles.statusGrid>
        {
          consignment.packageSet[0].eventSet
          |> Array.map((event: ConsignmentData.event)
               /* Currently reason doesn't support keyed fragments */
               =>
                 <>
                   <div> {event.city |> ReasonReact.string} </div>
                   <div>
                     <div> {event.description |> ReasonReact.string} </div>
                     <small className=Styles.timestamp>
                       {
                         event.displayDate
                         ++ " "
                         ++ event.displayTime
                         |> ReasonReact.string
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