import Navbar from "./navbar"
import 'react-dropdown/style.css';
import * as React from 'react';
import Select from "./Select";
import Bisection from "../Root_of_Equation/Bisection_search";


export default function Home() {
    const [open, setOpen] = React.useState(false);

    const handleOpen = () => {
        setOpen(!open);
    };
    return (
        <>
            <Navbar />
            <Select />
            {/* <Bisection /> */}
        </>
    )

}