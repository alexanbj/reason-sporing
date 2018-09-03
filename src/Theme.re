open Css;

let textColor = rgb(44, 62, 80);
let containerPixelWidth = 980;

/* Global styles / poor man's CSS reset */
global(
  "html",
  [
    boxSizing(borderBox),
    unsafe("WebkitFontSmoothing", "antialiased"),
    unsafe("MozOsxFontSmoothing", "grayscale"),
  ],
);

/* TODO: Remove unsafe when inherit is properly supported https://github.com/SentiaAnalytics/bs-css/issues/75 */
global("*, *::before, *::after", [unsafe("boxSizing", "inherit")]);

global(
  "body",
  [
    backgroundColor(white),
    margin(zero),
    color(textColor),
    fontFamily(
      "'-apple-system', 'BlinkMacSystemFont', 'Segoe UI', 'Roboto', 'Helvetica Neue', 'Arial', 'sans-serif', 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'",
    ),
  ],
);