import { Link } from "react-router-dom";
import { useSelector } from "react-redux";

function CartMini(){

    const cart = useSelector(state => state.cartReducer);

    const totalQuantity = cart.reduce((sum, item) => {
        return sum + item.quantity;
    }, 0);

    return(
        <>
            <Link to="/cart" className="layout-default__cart">Giỏ hàng ({totalQuantity})</Link>
        </>
    )
}
export default CartMini;