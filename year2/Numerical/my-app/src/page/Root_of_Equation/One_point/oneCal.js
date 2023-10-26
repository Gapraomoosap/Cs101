import { Button } from "react-bootstrap";
import { useState } from "react"
import {  evaluate } from 'mathjs'

const errorCal = (xold, xnew) => Math.abs((xnew - xold) / xnew) * 100;
export default function OnePoint() {
    const calGraph = (Xn, error) => {
        //calculate function
        const func = (x) => {
            var scope = { x: x };
            return evaluate(Equation, scope);
        };
        let inter=0,X_Old=0,X_Cur=func(Xn),ea
        let obj = {}
        ea = errorCal(X_Old,X_Cur)
        obj = {
            iteration : inter,
            Xk : parseFloat(X_Cur.toFixed(6)),
            error : 0
        }
        data.push(obj)
        inter++
        while(ea > error){
            X_Old = X_Cur
            X_Cur = func(X_Old)
            ea = errorCal(X_Old,X_Cur)
            obj = {
                iteration : inter,
                Xk : parseFloat(X_Cur.toFixed(7)),
                error : parseFloat(ea.toFixed(7))
            }
            data.push(obj)
            inter++
        }
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
                            <th className="border-2">error%</th>
                        </tr>
                    </thead>
                    <tbody>
                        {data.map((item, index) => (
                            <tr key={index} className="border-2">
                                <td className="border-2">{item.iteration}</td>
                                <td className="border-2">{item.Xk}</td>
                                <td className="border-2">{item.error} %</td>
                            </tr>
                        ))}
                    </tbody>
                </table>
            </div>
        )
    }
    
    const data = []
    const [html, setHtml] = useState(null)
    const [Xn, setXn] = useState(10)
    const [Equation, setEquation] = useState("(x^4)-13")
    const [Error, setError] = useState(0)
    const inputXn = (event) => {
        setXn(event.target.value)
        console.log(Xn)
    }
    const inputEquation = (event) => {
        setEquation(event.target.value)
        console.log(Equation)
    }
    const inputError = (event) => {
        setError(event.target.value)
    }
    const calculateRoot = () => {
        const xn = parseFloat(Xn)
        const error = parseFloat(Error)
        calGraph(xn, error)
        setHtml(print())
    }
    return (
        <div className="flex flex-col justify-center items-center mt-10 ">
            <div className=" max-w-sm">
                <h1 className="text-4xl mb-10">One-point Iteration methods</h1>
                <div>
                    <form>
                        <div className="flex flex-col mb-4">
                            <label>Xn+1</label>
                            <input type="text" id="equation" onChange={inputEquation} className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>X Initial</label>
                            <input type="number" id="Xn" onChange={inputXn} className="border-2" />
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
