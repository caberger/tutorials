const {resolve, join} = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
const {CleanWebpackPlugin} = require('clean-webpack-plugin')

const IS_DEV_SERVER = !!process.argv.find(arg => arg.includes('webpack-dev-server'))
const OUTPUT_PATH=resolve(__dirname, "dist")
const VENDOR_FOLDER = "vendor"
const devtool = IS_DEV_SERVER ? "cheap-source-map" : "none"
const mode = IS_DEV_SERVER ? "development" : "production"
module.exports = {
  mode,
  entry: './src/index.js',
  output: {
    filename: 'main.js',
    path: resolve(__dirname, 'dist')
  },
  plugins: [
      new HtmlWebpackPlugin({
        filename: resolve(OUTPUT_PATH, 'index.html'),
        template: `${resolve('./index.html')}`,
        compile: true,
        paths: {
          webcomponents: `${VENDOR_FOLDER}/webcomponents-bundle.js`, // ... does currently not work with Edge Browser if defer is used in script tag
        }
      }),
      new CopyWebpackPlugin([
        {
          from: resolve('./node_modules/@webcomponents/webcomponentsjs/webcomponents-bundle.js'),
          to: join(OUTPUT_PATH, VENDOR_FOLDER),
          flatten: true
        }        
      ]),
      new CleanWebpackPlugin({verbose: true})
  ],
  devtool,       
  devServer: {
    contentBase: OUTPUT_PATH,
    compress: false,
    port: 4000,
    hot: true,
    host: '0.0.0.0',
    disableHostCheck: true,
    historyApiFallback: true,
  }  
}
console.log("exports:", module.exports)