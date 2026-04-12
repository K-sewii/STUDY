import { useSelector } from "react-redux";
import "./Cart.scss";
import CartItem from "./CartItem";

function CartList() {
  const cart = useSelector((state) => state.cartReducer);

  return (
    <>
      <div className="cart">
        {cart.map((item) => (
          <CartItem key={item.id} item={item} />
        ))}
      </div>
    </>
  );
}

export default CartList;
