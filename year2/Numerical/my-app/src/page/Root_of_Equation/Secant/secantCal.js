import { Button } from "react-bootstrap";
import { useState } from "react"
import { evaluate } from 'mathjs'

const errorCal = (xold, xnew) => Math.abs((xnew - xold) / xnew) * 100;
export default function SecantCal() {
    const calNewton = (Xn0, Xn1, errorValue) => {
        const func = (x) => {
            var scope = { x: x };
            return evaluate(Equation, scope);
        };
        const NewFunc = (value, value2) => {
            return (value2 - func(value2)*((value2 - value) / (func(value2) - func(value))))
        }

        let inter = 0, X_Old = 0, X_Older, X_Cur = NewFunc(Xn0, Xn1), ea
        let obj = {}
        ea = errorCal(X_Old, X_Cur)
        obj = {
            iteration: inter,
            Xk: parseFloat(Xn0.toFixed(6)),
            Yk: parseFloat(X_Cur.toFixed(6)),
            error: ea.toFixed(6)
        }
        data.push(obj)
        inter++
        X_Older = Xn0
        X_Old = Xn1
        while (inter<10) {
            X_Old = X_Cur
            console.log("Xolder = ",X_Older," Xold = ",X_Old)
            X_Cur = NewFunc(X_Older, X_Old)
            X_Older = X_Old
            ea = errorCal(X_Old, X_Cur)
            obj = {
                iteration: inter,
                Xk: parseFloat(X_Cur.toFixed(6)),
                Yk: parseFloat(X_Old.toFixed(6)),
                error: ea.toFixed(6)
            }
            data.push(obj)
            inter++
        }
    }

    const print = () => {
        return (
            <div>
                <table className="border-2">
                    <thead>
                        <tr className="border-2">
                            <th className="border-2">Iteration</th>
                            <th className="border-2">Xk</th>
                            <th className="border-2">Yk</th>
                            <th className="border-2">error%</th>
                        </tr>
                    </thead>
                    <tbody>
                        {data.map((item, index) => (
                            <tr key={index} className="border-2">
                                <td className="border-2">{item.iteration}</td>
                                <td className="border-2">{item.Xk}</td>
                                <td className="border-2">{item.Yk}</td>
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
    const [Xn0, setXn0] = useState(10)
    const [Xn1, setXn1] = useState(10)
    const [Equation, setEquation] = useState("(x^4)-13")
    const [Error, setError] = useState(0)
    const inputXn0 = (event) => {
        setXn0(event.target.value)
    }
    const inputXn1 = (event) => {
        setXn1(event.target.value)
    }
    const inputEquation = (event) => {
        setEquation(event.target.value)
    }
    const inputError = (event) => {
        setError(event.target.value)
    }
    const calculateRoot = () => {
        const xn0 = parseFloat(Xn0)
        const xn1 = parseFloat(Xn1)
        const error = parseFloat(Error)
        calNewton(xn0, xn1, error)
        setHtml(print())
    }
    return (
        <div className="flex flex-col justify-center items-center mt-10 ">
            <div className=" max-w-sm">
                <h1 className="text-4xl mb-10">Secant methods</h1>
                <div>
                    <form>
                        <div className="flex flex-col mb-4">
                            <label>Fx</label>
                            <input type="text" id="equation" onChange={inputEquation} className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>X0</label>
                            <input type="number" id="Xn" onChange={inputXn0} className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>X1</label>
                            <input type="number" id="Xn" onChange={inputXn1} className="border-2" />
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