import { Button } from "react-bootstrap";
import { LineChart, Line, CartesianGrid, XAxis, YAxis } from 'recharts';
const data = [{ name: 'Page A', uv: 400, pv: 2400, amt: 2400 }, { name: 'Page B', uv: 600, pv: 2500, amt: 2700 }];
export default function Graphcal() {
    return (
        <div className="flex flex-col justify-center items-center mt-10 ">
            <div className=" max-w-sm">
                <h1 className="text-4xl mb-10">Graphical methods</h1>
                <div>
                    <form>
                        <div className="flex flex-col mb-4">
                            <label>f(x)</label>
                            <input type="text" className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>XL</label>
                            <input type="text" className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>XR</label>
                            <input type="text" className="border-2" />
                        </div>

                        <div className="flex flex-col mb-4">
                            <label>Error</label>
                            <input type="text" className="border-2" />
                        </div>
                    </form>
                    <div className="flex justify-end">
                        <Button className="border-2 p-2 rounded">OK</Button>{' '}
                    </div>
                </div>
            </div>
            <div className="mt-10">
                <LineChart width={600} height={300} data={data} margin={{ top: 5, right: 20, bottom: 5, left: 0 }}>
                    <Line type="monotone" dataKey="uv" stroke="#8884d8" />
                    <CartesianGrid stroke="#ccc" strokeDasharray="5 5" />
                    <XAxis dataKey="name" />
                    <YAxis />
                </LineChart>
            </div>
        </div>


    );
}
