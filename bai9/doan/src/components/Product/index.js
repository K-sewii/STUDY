import { useEffect, useState } from "react";
import { getProductList } from "../../services/productsService";
import "./Product.scss";
import ProuductItem from "./ProductItem";

function Product() {
  const [products, setProducts] = useState([]);
  useEffect(() => {
    const fetchApi = async () => {
      const result = await getProductList();
      setProducts(result);
    };
    fetchApi();
  }, []);

  console.log(products);
  return (
    <>
        {products.length > 0 &&(
            <div className="product">
                {products.map((product) => (
                    <ProuductItem key={product.id} product={product} />
                ))}
            </div>
        )}

    </>
  );
}

export default Product;
