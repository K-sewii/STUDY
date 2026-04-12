import { useDispatch } from "react-redux";
import { updateCart } from "../../actions/cart";
import { useRef } from "react";
import { deleteItem } from "../../actions/cart";

function CartItem(props){
    const {item} = props;
    const dispatch = useDispatch();
    const inputRef = useRef();


    const handleUp = () => {
        dispatch(updateCart(item.id, 1));
        inputRef.current.value = parseInt(inputRef.current.value) + 1;
    }

    const handleDown = () => {
        if (item.quantity > 1) {
            dispatch(updateCart(item.id, -1));
            inputRef.current.value = parseInt(inputRef.current.value) - 1;
        }
    }

    const handleDelete = () => {
        dispatch(deleteItem(item.id));
    }

    return(
        <>
        <div className="cart__item">
            <div className="cart__item__img">
              <img src={item.info.images[0]} alt={item.info.title} />
            </div>
            <div className="cart__item__content">
              <h4 className="cart__item__title">{item.info.title}</h4>
              <h4 className="cart__item__price-new">
                $
                {(
                  (item.info.price * (100 - item.info.discountPercentage)) /
                  100
                ).toFixed(0)}
                $
              </h4>
              <h4 className="cart__item__price-old">
                ${item.info.price.toFixed(0)}$
              </h4>
            </div>
            <div className="cart__item__quantity">
              <button onClick={handleDown}>-</button>
              <input ref={inputRef} defaultValue={item.quantity} />
              <button onClick={handleUp}>+</button>
            </div>
            <button onClick={handleDelete}>Xoa</button>
          </div>
        </>
    );
}

export default CartItem;