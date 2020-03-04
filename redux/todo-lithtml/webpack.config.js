const {resolve, join} = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')

const IS_DEV_SERVER = !!process.argv.find(arg => arg.includes('webpack-dev-server'))
const OUTPUT_PATH=resolve(__dirname, "dist")
const CONTENT_BASE = OUTPUT_PATH

module.exports = {
  mode: "development",
  entry: './src/index.js',
  output: {
    filename: 'main.js',
    path: resolve(__dirname, 'dist')
  },
  plugins: [
      new HtmlWebpackPlugin({
        filename: resolve(OUTPUT_PATH, 'index.html'),
        template: `${resolve('./index.html')}`,
        compile: true
      })
  ],
  devtool: 'inline-source-map',       
  devServer: {
    contentBase: CONTENT_BASE,
    compress: false,
    port: 4000,
    hot: true,
    host: '0.0.0.0',
    disableHostCheck: true,
    historyApiFallback: true,
  }  
}
