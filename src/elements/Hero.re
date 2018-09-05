module Styles = {
  open Css;

  let hero =
    style([
      padding2(rem(9.0), rem(1.5)),
      backgroundImage(
        url(
          "data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHhtbG5zOnhsaW5rPSJodHRwOi8vd3d3LnczLm9yZy8xOTk5L3hsaW5rIiB4bWxuczpmaT0iaHR0cDovL3BhdHRlcm4uZmxhdGljb24uY29tLyIgeD0iMCIgeT0iMCIgd2lkdGg9IjYwMCIgaGVpZ2h0PSIxODAiIHZpZXdCb3g9IjAgMCA2MDAgMTgwIj48cmVjdCB4PSIwcHgiIHk9IjBweCIgd2lkdGg9IjEwMCUiIGhlaWdodD0iMTAwJSIgb3BhY2l0eT0iMSIgZmlsbD0iI2ZmZmZmZiIvPjxkZWZzPjxnIHRyYW5zZm9ybT0ibWF0cml4KDAuMTE3MTg3NSAwIDAgMC4xMTcxODc1IDM4IDM0KSIgaWQ9IkwxXzI0Ij48cGF0aCBkPSJNNDkxLjcyOSwxMTIuOTcxTDI1OS4yNjEsMC43NDVjLTIuMDYxLTAuOTk0LTQuNDYxLTAuOTk0LTYuNTIxLDBMMjAuMjcxLDExMi45NzFjLTIuNTkyLDEuMjUxLTQuMjM5LDMuODc2LTQuMjM5LDYuNzU0ICAgIHYyNzIuNTQ5YzAsMi44NzgsMS42NDcsNS41MDMsNC4yMzksNi43NTRsMjMyLjQ2OCwxMTIuMjI2YzEuMDMsMC40OTcsMi4xNDYsMC43NDYsMy4yNjEsMC43NDZzMi4yMy0wLjI0OSwzLjI2MS0wLjc0NiAgICBsMjMyLjQ2OC0xMTIuMjI2YzIuNTkyLTEuMjUxLDQuMjM5LTMuODc2LDQuMjM5LTYuNzU0VjExOS43MjZDNDk1Ljk2OCwxMTYuODQ2LDQ5NC4zMiwxMTQuMjIzLDQ5MS43MjksMTEyLjk3MXogTTI1NiwxNS44MjggICAgbDIxNS4yMTcsMTAzLjg5N2wtNjIuMzg3LDMwLjExOGMtMC4zOTUtMC4zMDEtMC44MTItMC41NzktMS4yNy0wLjhMMTkzLjgwNSw0NS44NTNMMjU2LDE1LjgyOHogTTE3Ni44NjcsNTQuMzMzbDIxNC45MDQsMTAzLjc0NiAgICBsLTQ0LjAxNSwyMS4yNDlMMTMyLjk0MSw3NS42MjRMMTc2Ljg2Nyw1NC4zMzN6IE0zOTYuNzk5LDE3Mi4zMDd2NzguNTQ2bC00MS4xMTMsMTkuODQ4di03OC41NDZMMzk2Ljc5OSwxNzIuMzA3eiAgICAgTTQ4MC45NjgsMzg3LjU2OEwyNjMuNSw0OTIuNTVWMjM2LjY1OGw1MS44NzMtMjUuMDQyYzMuNzMtMS44MDEsNS4yOTQtNi4yODQsMy40OTMtMTAuMDE1ICAgIGMtMS44MDEtMy43MjktNi4yODQtNS4yOTUtMTAuMDE1LTMuNDkzTDI1NiwyMjMuNjIzbC0yMC43OTYtMTAuMDRjLTMuNzMxLTEuODAzLTguMjE0LTAuMjM3LTEwLjAxNSwzLjQ5MyAgICBjLTEuODAxLDMuNzMtMC4yMzcsOC4yMTQsMy40OTMsMTAuMDE1bDE5LjgxOCw5LjU2N1Y0OTIuNTVMMzEuMDMyLDM4Ny41NjZWMTMxLjY3NGwxNjUuNiw3OS45NDUgICAgYzEuMDUxLDAuNTA4LDIuMTYyLDAuNzQ4LDMuMjU1LDAuNzQ4YzIuNzg4LDAsNS40NjYtMS41NjIsNi43NTktNC4yNDFjMS44MDEtMy43MywwLjIzNy04LjIxNC0zLjQ5My0xMC4wMTVsLTE2Mi4zNy03OC4zODYgICAgbDc0LjUwNS0zNS45NjhMMzQwLjU4MiwxOTIuNTJjMC4wMzMsMC4wNDYsMC4wNywwLjA4NywwLjEwNCwwLjEzMnY4OS45OTljMCwyLjU4MSwxLjMyNyw0Ljk4LDMuNTEzLDYuMzUzICAgIGMxLjIxNCwwLjc2MiwyLjU5OSwxLjE0NywzLjk4OCwxLjE0N2MxLjExMiwwLDIuMjI3LTAuMjQ3LDMuMjYtMC43NDZsNTYuMTEzLTI3LjA4OWMyLjU5Mi0xLjI1MSw0LjIzOS0zLjg3NSw0LjIzOS02Ljc1NHYtOTAuNDk1ICAgIGw2OS4xNjktMzMuMzkyVjM4Ny41Njh6Ii8+PHBhdGggZD0iTTkyLjkyNiwzNTguNDc5TDU4LjgxMSwzNDIuMDFjLTMuNzMyLTEuODAzLTguMjE0LTAuMjM3LTEwLjAxNSwzLjQ5M2MtMS44MDEsMy43My0wLjIzNyw4LjIxNCwzLjQ5MywxMC4wMTUgICAgbDM0LjExNSwxNi40NjljMS4wNTEsMC41MDgsMi4xNjIsMC43NDgsMy4yNTUsMC43NDhjMi43ODgsMCw1LjQ2Ni0xLjU2Miw2Ljc1OS00LjI0MSAgICBDOTguMjIsMzY0Ljc2Myw5Ni42NTYsMzYwLjI4MSw5Mi45MjYsMzU4LjQ3OXoiLz48cGF0aCBkPSJNMTI0LjMyMywzMzguMDQybC02NS40NjUtMzEuNjA0Yy0zLjczMS0xLjgwMS04LjIxNC0wLjIzNy0xMC4wMTUsMy40OTRjLTEuOCwzLjczLTAuMjM2LDguMjE0LDMuNDk0LDEwLjAxNSAgICBsNjUuNDY1LDMxLjYwNGMxLjA1MSwwLjUwNywyLjE2MiwwLjc0OCwzLjI1NSwwLjc0OGMyLjc4OCwwLDUuNDY2LTEuNTYyLDYuNzU5LTQuMjQxICAgIEMxMjkuNjE3LDM0NC4zMjYsMTI4LjA1MywzMzkuODQyLDEyNC4zMjMsMzM4LjA0MnoiLz48L2c+PHBhdGggZD0iTTYwOS4xMywxMjYuNDg0Yy0yLjM0OC0yLjU0OC02LjE1Ni0zLjEzLTkuMTc1LTEuNDAxbC0xMjYuNjU4LDcyLjczOEwyOTguNTM5LDk5LjQyMyAgIGMtMC4zNzMtMC4yMDgtMC43NzUtMC4zMjgtMS4xNjMtMC40NjlMMjQ4LjI1NSw0LjYzM2MtMC45MjQtMS43ODEtMi41MjYtMy4xMDgtNC40NDktMy42ODljLTEuOTA4LTAuNTc0LTMuOTg3LTAuMzY1LTUuNzQ2LDAuNjA0ICAgTDMuODY3LDEzMC4xNThjLTEuNzQ0LDAuOTU0LTMuMDI2LDIuNTcxLTMuNTg1LDQuNDg2Yy0wLjUzNywxLjkxNi0wLjMwNiwzLjk2NSwwLjY3MSw1LjcwMmw1NS40ODUsOTcuMzYyICAgYy0wLjAyMiwwLjIwMSwwLjcsMC4zODgsMC43LDAuNTk2YzAsMC4wMTUsMCwwLjAzLDAsMC4wNDVjMCwwLjAxNSwwLDAuMDMsMCwwLjA0NHYyMjIuOTU1SDU1LjdjMCwwLDEuMTU1LDYuNDgzLDMuNDczLDcuODc3ICAgbDIzMS44NzUsMTQwLjY5OWMxLjE4NSwwLjcyNCwyLjUxMiwxLjQ1NCwzLjg1MywxLjQ1NGMxLjMxMiwwLDIuNjI0LTAuMTU3LDMuODAxLTAuODVsMjM2LjYyNC0xNDEuMzU1ICAgYzIuMzQtMS4zODcsMy41MjQtNy44MTgsMy41MjQtNy44MThoMi43MjFWMjM5LjQ4Mmw2OS41NDktMTAzLjczNEM2MTMuMDgsMTMyLjg3OCw2MTEuNSwxMjkuMDMzLDYwOS4xMywxMjYuNDg0eiBNMjYwLjg1MSwzNDYuNzU1ICAgbDM0LjM1LTIxLjk0bDE5Ljg1NCwxMi45NjhsLTE4LjcwNiwyOS45ODFMMjYwLjg1MSwzNDYuNzU1eiBNMjg4LjE3MiwzMTIuMDc4bC00MS4zNCwyNi4xODJMNzguMzk0LDIzOC40OThsMjA5Ljc3OC0xMTkuNzUgICBWMzEyLjA3OHogTTcyLjA0NCwyNTEuNTkybDIxNi4xMjgsMTMwLjk4djIwOC41MTJMNzIuMDQ0LDQ2MC4xMzNWMjUxLjU5MnogTTMwMy4wNzgsMzgyLjYxOGwyMjMuNTgxLTEzMS4xNjd2MjA4LjYzICAgTDMwMy4wNzgsNTkxLjIxOFYzODIuNjE4eiBNMzIzLjMxOSwzMjUuMTI3bC0yMC4yNDItMTMuNDUyVjExOC42NzRsMTU1LjUzLDg3Ljc5MmwtOTQuMDE2LDUzLjg5MSAgIGMtMS4wNjUsMC42MTEtMS44NzgsMS40NzYtMi41MTksMi41MTlMMzIzLjMxOSwzMjUuMTI3eiBNMjM4LjU1MiwxOC4yNzFsNDQuNjQ5LDg1Ljc0M0w2Ny4wMjgsMjI3LjUxM2wtNDkuMzk2LTg3LjkxMiAgIEwyMzguNTUyLDE4LjI3MXogTTUyNS4zNjEsMjMyLjk4M2wwLjMwNiwwLjIwOUwzMjMuMTMzLDM1M2w1MC4zMi04MC42NTJsMjA1LjcwMi0xMTguMTMyTDUyNS4zNjEsMjMyLjk4M3oiIHRyYW5zZm9ybT0ibWF0cml4KDAuMDk4MDM4NDEyNjMwNTU4MDEgMCAwIDAuMDk4MDM4NDEyNjMwNTU4MDEgMTc1IDYzLjAwMDAwNTU1Mjk1NjM5NSkiIGlkPSJMMV8yNSIvPjxnIHRyYW5zZm9ybT0ibWF0cml4KC0xLjkzNDczNDk0MDUyODg2OTYgMCAwIDEuOTM0NzM0OTQwNTI4ODY5NiAxNDAuOTc2NzgzMTU2Mzk0OTYgMTI1LjAwMDAwMzcxOTczNTU2KSIgaWQ9IkwxXzI2Ij48Zz48cGF0aCBkPSJNMjUuMTA5LDIxLjUxYy0wLjEyMywwLTAuMjQ2LTAuMDQ1LTAuMzQyLTAuMTM2bC01Ljc1NC01LjM5OGMtMC4yMDEtMC4xODgtMC4yMTEtMC41MDUtMC4wMjItMC43MDYgICAgYzAuMTg5LTAuMjAzLDAuNTA0LTAuMjEyLDAuNzA3LTAuMDIybDUuNzU0LDUuMzk4YzAuMjAxLDAuMTg4LDAuMjExLDAuNTA1LDAuMDIyLDAuNzA2QzI1LjM3NSwyMS40NTcsMjUuMjQzLDIxLjUxLDI1LjEwOSwyMS41MXogICAgIi8+PHBhdGggZD0iTTUuOTAyLDIxLjUxYy0wLjEzMywwLTAuMjY2LTAuMDUzLTAuMzY1LTAuMTU4Yy0wLjE4OS0wLjIwMS0wLjE3OS0wLjUxOCwwLjAyMi0wLjcwNmw1Ljc1Ni01LjM5OCAgICBjMC4yMDItMC4xODgsMC41MTktMC4xOCwwLjcwNywwLjAyMmMwLjE4OSwwLjIwMSwwLjE3OSwwLjUxOC0wLjAyMiwwLjcwNmwtNS43NTYsNS4zOThDNi4xNDgsMjEuNDY1LDYuMDI1LDIxLjUxLDUuOTAyLDIxLjUxeiIvPjwvZz48cGF0aCBkPSJNMjguNTEyLDI2LjUyOUgyLjVjLTEuMzc4LDAtMi41LTEuMTIxLTIuNS0yLjVWNi45ODJjMC0xLjM3OSwxLjEyMi0yLjUsMi41LTIuNWgyNi4wMTJjMS4zNzgsMCwyLjUsMS4xMjEsMi41LDIuNXYxNy4wNDcgICBDMzEuMDEyLDI1LjQwOCwyOS44OSwyNi41MjksMjguNTEyLDI2LjUyOXogTTIuNSw1LjQ4MmMtMC44MjcsMC0xLjUsMC42NzMtMS41LDEuNXYxNy4wNDdjMCwwLjgyNywwLjY3MywxLjUsMS41LDEuNWgyNi4wMTIgICBjMC44MjcsMCwxLjUtMC42NzMsMS41LTEuNVY2Ljk4MmMwLTAuODI3LTAuNjczLTEuNS0xLjUtMS41SDIuNXoiLz48cGF0aCBkPSJNMTUuNTA2LDE4LjAxOGMtMC42NjUsMC0xLjMzLTAuMjIxLTEuODM2LTAuNjYyTDAuODMsNi4xNTVDMC42MjIsNS45NzQsMC42LDUuNjU4LDAuNzgxLDUuNDQ5ICAgYzAuMTgzLTAuMjA4LDAuNDk4LTAuMjI3LDAuNzA2LTAuMDQ4bDEyLjg0LDExLjJjMC42MzksMC41NTcsMS43MTksMC41NTcsMi4zNTcsMEwyOS41MDgsNS40MTkgICBjMC4yMDctMC4xODEsMC41MjItMC4xNjEsMC43MDYsMC4wNDhjMC4xODEsMC4yMDksMC4xNiwwLjUyNC0wLjA0OCwwLjcwNkwxNy4zNDIsMTcuMzU1ICAgQzE2LjgzNSwxNy43OTcsMTYuMTcxLDE4LjAxOCwxNS41MDYsMTguMDE4eiIvPjwvZz48L2RlZnM+PGcgZmk6Y2xhc3M9IktVc2VQYXR0ZXJuIiBvcGFjaXR5PSIwLjIiPjxwYXR0ZXJuIGlkPSJwYXR0ZXJuX0wxXzI0IiB3aWR0aD0iMzUwIiBoZWlnaHQ9IjM1MCIgcGF0dGVyblVuaXRzPSJ1c2VyU3BhY2VPblVzZSI+PHVzZSB4bGluazpocmVmPSIjTDFfMjQiIHg9Ii0zNTAiIHk9Ii0zNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNCIgeD0iMCIgeT0iLTM1MCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI0IiB4PSIzNTAiIHk9Ii0zNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNCIgeD0iLTM1MCIgeT0iMCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI0IiB4PSIwIiB5PSIwIi8+PHVzZSB4bGluazpocmVmPSIjTDFfMjQiIHg9IjM1MCIgeT0iMCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI0IiB4PSItMzUwIiB5PSIzNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNCIgeD0iMCIgeT0iMzUwIi8+PHVzZSB4bGluazpocmVmPSIjTDFfMjQiIHg9IjM1MCIgeT0iMzUwIi8+PC9wYXR0ZXJuPjxyZWN0IHg9IjAiIHk9IjAiIHdpZHRoPSIxMDAlIiBoZWlnaHQ9IjEwMCUiIGZpbGw9InVybCgjcGF0dGVybl9MMV8yNCkiLz48L2c+PGcgZmk6Y2xhc3M9IktVc2VQYXR0ZXJuIiBvcGFjaXR5PSIwLjIiPjxwYXR0ZXJuIGlkPSJwYXR0ZXJuX0wxXzI2IiB3aWR0aD0iMzUwIiBoZWlnaHQ9IjM1MCIgcGF0dGVyblVuaXRzPSJ1c2VyU3BhY2VPblVzZSI+PHVzZSB4bGluazpocmVmPSIjTDFfMjYiIHg9Ii0zNTAiIHk9Ii0zNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNiIgeD0iMCIgeT0iLTM1MCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI2IiB4PSIzNTAiIHk9Ii0zNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNiIgeD0iLTM1MCIgeT0iMCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI2IiB4PSIwIiB5PSIwIi8+PHVzZSB4bGluazpocmVmPSIjTDFfMjYiIHg9IjM1MCIgeT0iMCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI2IiB4PSItMzUwIiB5PSIzNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNiIgeD0iMCIgeT0iMzUwIi8+PHVzZSB4bGluazpocmVmPSIjTDFfMjYiIHg9IjM1MCIgeT0iMzUwIi8+PC9wYXR0ZXJuPjxyZWN0IHg9IjAiIHk9IjAiIHdpZHRoPSIxMDAlIiBoZWlnaHQ9IjEwMCUiIGZpbGw9InVybCgjcGF0dGVybl9MMV8yNikiLz48L2c+PGcgZmk6Y2xhc3M9IktVc2VQYXR0ZXJuIiBvcGFjaXR5PSIwLjIiPjxwYXR0ZXJuIGlkPSJwYXR0ZXJuX0wxXzI1IiB3aWR0aD0iMzUwIiBoZWlnaHQ9IjM1MCIgcGF0dGVyblVuaXRzPSJ1c2VyU3BhY2VPblVzZSI+PHVzZSB4bGluazpocmVmPSIjTDFfMjUiIHg9Ii0zNTAiIHk9Ii0zNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNSIgeD0iMCIgeT0iLTM1MCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI1IiB4PSIzNTAiIHk9Ii0zNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNSIgeD0iLTM1MCIgeT0iMCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI1IiB4PSIwIiB5PSIwIi8+PHVzZSB4bGluazpocmVmPSIjTDFfMjUiIHg9IjM1MCIgeT0iMCIvPjx1c2UgeGxpbms6aHJlZj0iI0wxXzI1IiB4PSItMzUwIiB5PSIzNTAiLz48dXNlIHhsaW5rOmhyZWY9IiNMMV8yNSIgeD0iMCIgeT0iMzUwIi8+PHVzZSB4bGluazpocmVmPSIjTDFfMjUiIHg9IjM1MCIgeT0iMzUwIi8+PC9wYXR0ZXJuPjxyZWN0IHg9IjAiIHk9IjAiIHdpZHRoPSIxMDAlIiBoZWlnaHQ9IjEwMCUiIGZpbGw9InVybCgjcGF0dGVybl9MMV8yNSkiLz48L2c+PC9zdmc+",
        ),
      ),
    ]);
};

let component = ReasonReact.statelessComponent("Hero");

let make = children => {
  ...component,
  render: _self => <div className=Styles.hero> ...children </div>,
};