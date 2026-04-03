const express = require("express");
const route = require("./routes/client/index.route");
require("dotenv").config();

const app = express();
const port = process.env.PORT;

app.use(express.static("public"));

app.set("view engine", "pug");
app.set("views", "./views");

route(app);
// app.get("/", (req, res) => {
//   res.render("client/pages/home/index");
// });

// app.get("/products", (req, res) => {
//   res.render("client/pages/products/index");
// });

app.listen(port, () => {
  console.log(`Server dang chay tai http://localhost:${port}`);
});
