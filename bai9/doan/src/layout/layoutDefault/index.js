import { Link, Outlet } from "react-router-dom";
import  "./layoutDefault.scss";
import CartMini from "../../components/CartMini";

function LayoutDefault() {
    return (
        <>
        <div className="layout-default">
            <header className="layout-default__header">
                <Link to="/" className="layout-default__logo">Logo</Link>
               <CartMini />
            </header>
            <main className="layout-default__main">
                <Outlet />
            </main>
            <footer className="layout-default__footer">
                copyright @ 2024
            </footer>
        </div>
        </>
    );
}

export default LayoutDefault;