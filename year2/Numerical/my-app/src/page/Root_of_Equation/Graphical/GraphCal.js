import { Button } from "react-bootstrap";
import { useState } from "react"
import {  evaluate } from 'mathjs'
import ChartComponent from './GraphChart';

export default function Graphcal() {
    const calGraph = (xl, xr, error) => {
        //calculate function
        const func = (x) => {
            var scope = { x: x };
            return evaluate(Equation, scope);
        };
        let cur = func(xl), old = 0, index = 0
        let obj = {}
        let inter = 0
        obj = {
            iteration: inter,
            Xi: xl,
            Fxi: cur
        }
        inter++
        data.push(obj)
        for (let i = xl + 1; i < xr; i++) {
            if (old * cur < 0) {
                index = i - 2
                break;
            }
            else {
                old = cur;
                cur = func(i);
                if(old*cur >0){
                    obj = {
                        iteration: inter,
                        Xi: i,
                        Fxi: cur
                    }
                    data.push(obj)
                    inter++
                }
            }
        }
        while ((Math.abs(func(index)) > error)) {
            index = index + 0.0000001
        }
        obj = {
            iteration: inter,
            Xi: index.toFixed(6),
            Fxi: func(index).toFixed(6)
        }
        data.push(obj)
        console.log(data)
    };

    const print = () => {
        return (
            <div>
                <table className="border-2">
                    <thead>
                        <tr className="border-2">
                            <th className="border-2">Iteration</th>
                            <th className="border-2">Xk</th>
                            <th className="border-2">Yk</th>
                        </tr>
                    </thead>
                    <tbody>
                        {data.map((item, index) => (
                            <tr key={index} className="border-2">
                                <td className="border-2">{item.iteration}</td>
                                <td className="border-2">{item.Xi}</td>
                                <td className="border-2">{item.Fxi}</td>
                            </tr>
                        ))}
                    </tbody>
                </table>
                {data.length > 0 && <ChartComponent data={data} />}
            </div>
        )
    }

    const inputXL = (event) => {
        setXL(event.target.value)
    }
    const inputXR = (event) => {
        setXR(event.target.value)
    }
    const inputEquation = (event) => {
        setEquation(event.target.value)
    }
    const inputError = (event) => {
        setError(event.target.value)
    }
    const calculateRoot = () => {
        const xlnum = parseFloat(XL)
        const xrnum = parseFloat(XR)
        const error = parseFloat(Error)
        calGraph(xlnum, xrnum, error)
        setHtml(print())
    }
    const data = []
    const [html, setHtml] = useState(null)
    const [XL, setXL] = useState(0)
    const [XR, setXR] = useState(0)
    const [Equation, setEquation] = useState("(x^4)-13")
    const [Error, setError] = useState(0)
    return (
        <div className="flex flex-col justify-center items-center mt-10 ">
            <div className=" max-w-sm">
                <h1 className="text-4xl mb-10">Graphical methods</h1>
                <div>
                    <form>
                        <div className="flex flex-col mb-4">
                            <label>f(x)</label>
                            <input type="text" id="equation" onChange={inputEquation} className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>XL</label>
                            <input type="number" id="XL" onChange={inputXL} className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>XR</label>
                            <input type="number" id="XR" onChange={inputXR} className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>Error</label>
                            <input type="number" onChange={inputError} className="border-2" />
                        </div>
                    </form>
                    <div className="flex justify-end">
                        <Button className="border-2 p-2 rounded" onClick={calculateRoot}>OK</Button>{' '}
                    </div>
                </div>
                {html}
                
            </div>
        </div>


    );
}
