# posten

## Run Project

```sh
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `src/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Build for Production

```sh
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## SVGs

The SVG illustrations are taken from https://undraw.co/illustrations, using #ff6347 as the base color.

The hero pattern has been generated here https://pattern.flaticon.com/.

## Cypress tests

[The best practice](https://docs.cypress.io/guides/references/best-practices.html#Selecting-Elements) when using Cypress to target elements is to use data-\* attributes. ReasonReact [doesn't properly support these attributes](https://reasonml.github.io/reason-react/docs/en/invalid-prop-name), so our end to end tests will be more flaky than they should.
