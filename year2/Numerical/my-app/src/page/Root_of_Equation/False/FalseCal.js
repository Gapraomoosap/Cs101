import { useState } from "react"
import { Button, Container, Table } from "react-bootstrap";
import { evaluate } from 'mathjs'

const False = () => {
    const print = () => {
        console.log(data)
        setValueIter(data.map((x) => x.iteration));
        setValueXl(data.map((x) => x.Xl));
        setValueXm(data.map((x) => x.Xm));
        setValueXr(data.map((x) => x.Xr));
        return (
            <Container>
                <Table>
                    <thead>
                        <tr>
                            <th className="border-2" width="10%">Iteration</th>
                            <th className="border-2" width="30%">XL</th>
                            <th className="border-2" width="30%">XM</th>
                            <th className="border-2" width="30%">XR</th>
                        </tr>
                    </thead>
                    <tbody>
                        {data.map((element, index) => {
                            return (
                                <tr key={index}>
                                    <td className="border-2">{element.iteration}</td>
                                    <td className="border-2">{element.Xl}</td>
                                    <td className="border-2">{element.Xm}</td>
                                    <td className="border-2">{element.Xr}</td>
                                </tr>)
                        })}
                    </tbody>
                </Table>
            </Container>

        );
    }

    const error = (xold, xnew) => Math.abs((xnew - xold) / xnew) * 100;
    const Calbisection = (xl, xr) => {
        var xm, fXm, fXl, fXr, ea, scope;
        var iter = 0;
        const MAX = 50;
        const e = 0.00001;
        var obj = {};
        do {
            scope = { x: xr };
            fXr = evaluate(Equation, scope);
    
            scope = { x: xl };
            fXl = evaluate(Equation, scope);
    
            xm = (xl + xr) / 2;
            scope = { x: xm };
            fXm = evaluate(Equation, scope);
            iter++;
    
            if (fXm * fXr > 0) {
                ea = error(xr, xm);
                obj = {
                    iteration: iter,
                    Xl: xl,
                    Xm: xm,
                    Xr: xr
                };
                data.push(obj);
                xr = xm;
            } else if (fXm * fXr < 0) {
                ea = error(xl, xm);
                obj = {
                    iteration: iter,
                    Xl: xl,
                    Xm: xm,
                    Xr: xr
                };
                data.push(obj);
                xl = xm;
            }
        } while (ea > e && iter < MAX);
        setX(xm);
    };
    

    const data = [];
    const [valueIter, setValueIter] = useState([]);
    const [valueXl, setValueXl] = useState([]);
    const [valueXm, setValueXm] = useState([]);
    const [valueXr, setValueXr] = useState([]);


    const [html, setHtml] = useState(null);
    const [Equation, setEquation] = useState("(x^4)-13")
    const [X, setX] = useState(0)
    const [XL, setXL] = useState(0)
    const [XR, setXR] = useState(0)

    const inputEquation = (event) => {
        console.log(event.target.value)
        setEquation(event.target.value)
    }

    const inputXL = (event) => {
        console.log(event.target.value)
        setXL(event.target.value)
    }

    const inputXR = (event) => {
        console.log(event.target.value)
        setXR(event.target.value)
    }

    const calculateRoot = () => {
        const xlnum = parseFloat(XL)
        const xrnum = parseFloat(XR)
        Calbisection(xlnum, xrnum);

        setHtml(print());

        console.log(valueIter)
        console.log(valueXl)
    }

    return (
        <div className="flex flex-col justify-center items-center mt-10 ">
            <div className=" max-w-sm">
                <h1 className="text-4xl mb-10">False-position methods</h1>
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
                    </form>
                    <div className="flex justify-end">
                        <Button className="border-2 p-2 rounded" onClick={calculateRoot}>OK</Button>{' '}
                    </div>
                </div>
                {html}
            </div>
        </div>

    )
}

export default False