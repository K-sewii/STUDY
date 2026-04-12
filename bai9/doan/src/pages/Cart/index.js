import { useSelector } from "react-redux";
import CartList from "./CartList";
import { useDispatch } from "react-redux";
import { deleteAll } from "../../actions/cart";

function Cart() {
  const cart = useSelector((state) => state.cartReducer);
  const dispatch = useDispatch();

  const totalPrice = cart.reduce((sum, item) => {
    const newPrice = (item.info.price * (100 - item.info.discountPercentage)) / 100;
    return sum + newPrice * item.quantity;
  }, 0);


  const handleDeleteAll = () => {
    dispatch(deleteAll());
  }
  return (
    <>
      <h2>Giỏ hàng</h2>
      <button onClick={handleDeleteAll}>Xoa tat ca</button>

      {cart.length > 0 ? (
        <>
          <CartList />
          <div className="cart__item__total">
            Tong tien: <span>{totalPrice.toFixed(0)}$</span>
          </div>
        </>
      ) : (
        <p>Chua co san pham nao trong gio hang</p>
      )}
    </>
  );
}
export default Cart;
