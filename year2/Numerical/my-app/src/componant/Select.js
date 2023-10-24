import React, { useState } from 'react';
import '../App.css';
import { useNavigate } from 'react-router-dom';

const Select = () => {
    const [val, setVal] = useState('');
    const [val2, setVal2] = useState('');
    const navigate = useNavigate();

    const data = ["-", "Root of Equation", "Linear algebra equation", "Interpolation", "Extrapolation", "Integration"];
    const data2 = ["-", "Graphical methods", "Bisection search ", "False-position methods", "One-point Iteration methods ", "Newton-Raphson methods", "Secant methods"];
    const data3 = ["-", "Cramer's rule", "Guass elimination", "Guass Jordan elimination", "Matrix Inversion", "Jacobi Iteration Methods", "Conjugate Gradient Methods"];
    const data4 = ["-", "Newton divied-differences", "Lagrange interpolation", "Spline interpolation"];
    const data5 = ["-", "Simple Regression", "Multiple Regression"];
    const data6 = ["-", "Trapezoidal Rule", "Composite Trapezoidal Rule", "Simpson Rule", "Composite Simpson Rule"];
    const handleSelect2Change = (selectedValue) => {
        const formattedSelectedValue = selectedValue.replace(/ /g, '_');
        const paTh = "/" + formattedSelectedValue;
        navigate(paTh);
    };
    let select2Options = [];
    if (val === "Root of Equation") {
        select2Options = data2;
    } else if (val === "Linear algebra equation") {
        select2Options = data3;
    } else if (val === "Interpolation") {
        select2Options = data4;
    } else if (val === "Extrapolation") {
        select2Options = data5;
    } else if (val === "Integration") {
        select2Options = data6;
    }

    return (
        <div className='flex justify-center mt-8'>
            <div className="flex items-baseline">
                <h2 className='mx-4'>Type of problems</h2>
                <select className='border-4' value={val} onChange={e => setVal(e.target.value)}>
                    {data.map(opt => <option key={opt}>{opt}</option>)}
                </select>

                <h2 className='mx-4'>Solution</h2>
                <select className='border-4' value={val2} onChange={e => handleSelect2Change(e.target.value)}>
                    {select2Options.map((opt, index) => <option key={opt + index}>{opt}</option>)}
                </select>
            </div>


        </div>
    );
};

export default Select;
