import { useEffect, useRef } from 'react';
import { Chart } from 'chart.js/auto';
import Plot from 'react-plotly.js';

const ChartComponent = ({ data }) => {
  <>
        <Plot
        data={[
          {
            x: [1, 2, 3],
            y: [2, 6, 3],
            type: 'scatter',
            mode: 'lines+markers',
            marker: {color: 'red'},
          },
          {type: 'bar', x: [1, 2, 3], y: [2, 5, 3]},
        ]}
        layout={ {width: 320, height: 240, title: 'A Fancy Plot'} }
      />
  </>
};

export default ChartComponent;
