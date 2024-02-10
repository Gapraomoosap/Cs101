import { render } from "@testing-library/react";
import React from 'react'
import Table from '@mui/material/Table';
import TableBody from '@mui/material/TableBody';
import TableCell from '@mui/material/TableCell';
import TableContainer from '@mui/material/TableContainer';
import TableHead from '@mui/material/TableHead';
import TableRow from '@mui/material/TableRow';
import Paper from '@mui/material/Paper';
const Parser = require('expr-eval').Parser;


class InverseMatrix extends React.Component
{
    constructor(props) {
        super(props);
        this.state = {
          numRows: 3,
          numCols: 3,
          matrix: this.initializeMatrix(3, 3),
          result: this.initializeMatrix(3, 3),
        };
        this.handleChange = this.handleChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
      }
    
      initializeMatrix(rows, cols) {
        return Array.from({ length: rows }, () => Array(cols).fill(''));
      }
    BisectionCalcFunction(XL,Funct)
    {
        const parser = new Parser();
        function fx(x)
        {
            let expr = parser.parse(Funct)
            console.log("fx = "+expr.evaluate({ x: (x) }))
            return expr.evaluate({ x: (x) })
        }
      var xl = parseInt(XL);
      var arr = []
      var mz
      var i;
      for(i=1;i<=xl;i++){
        mz = fx(i)
        arr[i] = ({x:i,y:mz})
        //render(arr[i].x+": "+arr[i].y)
      }
      console.log(arr);
      render(
      <TableContainer component={Paper}>
        <Table sx={{ minWidth: 300 }} aria-label="simple table">
          <TableHead>
            <TableRow>
              <TableCell align="center">X</TableCell>
              <TableCell align="center">Y</TableCell>
            </TableRow>
          </TableHead>
          <TableBody>
            {arr.map((arr) => (
              <TableRow
                key={arr.x}
                sx={{ '&:last-child td, &:last-child th': { border: 0 } }}
              >
                <TableCell component="th" scope="row" align="center">
                  {arr.x}
                </TableCell>
                <TableCell align="center">{arr.y}</TableCell>
              </TableRow>
            ))}
          </TableBody>
        </Table>
      </TableContainer>
      )

    }
    handleSubmit(event){
        const {XL,Funct} = this.state
        const xm = this.BisectionCalcFunction(XL,Funct)
        event.preventDefault()
    }
    handleChange(event){
      this.setState({[event.target.name] : event.target.value});
    }
    render(){
        return(
          <div>
            <form onSubmit={this.handleSubmit}>
            <div>
                <h1 className="h1">&emsp;Bisection Method&emsp;</h1>
              <label htmlFor='XL' className="XLtext">&emsp;XL :&emsp;</label>
              <input
                className="XLfield"
                name='XL'
                placeholder='XL'
                value = {this.state.XL}
                onChange={this.handleChange}
                size='16'
              />
              </div>
              <p></p>
              <div>
              <label htmlFor='Funct' className="Functext">&emsp;Funct :&emsp;</label>
              <input
                className="Funcfield"
                name='Funct'
                placeholder='FUNCTION'
                value={this.state.Funct}
                onChange={this.handleChange}
                size='30'
              />
            </div>
            <p></p>
            <div>
            &emsp;<button className="hbutton">Calculate</button>
            </div>
          </form>
          </div>
        )
      }
    }

export default InverseMatrix