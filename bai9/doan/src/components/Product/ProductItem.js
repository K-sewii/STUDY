import { useDispatch } from "react-redux";
import { addToCart } from "../../actions/cart";
import { useSelector } from "react-redux";
import { updateCart } from "../../actions/cart";

function ProuductItem(props){
    const { product } = props;
    const dispatch = useDispatch();
    const cart = useSelector(state => state.cartReducer);

    const handleAddToCart = () => {
      if(cart.some(itemCart => itemCart.id === product.id)){
        dispatch(updateCart(product.id));
      
      }else{
        dispatch(addToCart(product.id, product));
      }
      console.log(cart);
    }


    return(
        <>
          <div className="product__item">
            <img
              className="product__image"
              src={product.images[0]}
              alt={product.title}
            ></img>
            <h3>{product.title}</h3>
            <div className="product__price-new">{(product.price * (100 - product.discountPercentage) / 100).toFixed(0)}$</div>
            <div className="product__price-old">{product.price}$</div>
            <div className="product__percent">
              {product.discountPercentage}%
            </div>
            <button onClick={handleAddToCart}>Add to cart</button>
          </div>
      </>
    );
}

export default ProuductItem;
