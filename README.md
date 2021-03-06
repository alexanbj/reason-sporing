# reason-sporing

## Run Project

```sh
yarn
yarn bs:start
# in another tab
yarn run start
```

After you see the webpack compilation succeed (the `yarn run start` step), open up `http://localhost:3000`.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Build for Production

```sh
yarn run build
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.

## Deploy

The application is deployed to [now.sh](https://zeit.co/now), by running the following in the same folder as the `package.json`.

```sh
now
```

If you want to build for production and serve locally for testing,

```sh
yarn run build
yarn run now-start
```

## SVGs

The SVG illustrations are taken from https://undraw.co/illustrations, using #ff6347 as the base color.

The hero pattern has been generated here https://pattern.flaticon.com/.

## Cypress tests

[The best practice](https://docs.cypress.io/guides/references/best-practices.html#Selecting-Elements) when using Cypress to target elements is to use data-\* attributes. ReasonReact [doesn't properly support these attributes](https://reasonml.github.io/reason-react/docs/en/invalid-prop-name), so our end to end tests will be more flaky than they should.
