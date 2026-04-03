const productRoute = require("./product.route");
const homeRoute = require("./home.route");

module.exports = (app) => {
  app.use("/", homeRoute);
  //   app.get("/", (req, res) => {
  //     res.render("client/pages/home/index");
  //   });

  app.use("/products", productRoute);

  //   app.get("/products", (req, res) => {
  //     res.render("client/pages/products/index");
  //   });
};
