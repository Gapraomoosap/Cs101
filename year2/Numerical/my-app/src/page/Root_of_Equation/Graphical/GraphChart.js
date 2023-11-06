import React, { useEffect, useRef } from 'react';
import Chart from 'chart.js';

const ChartComponent = ({ data }) => {
  const chartRef = useRef(null);

  useEffect(() => {
    const chartData = {
      labels: data.map(item => item.iteration),
      datasets: [{
        label: 'F(xi) vs Iteration',
        data: data.map(item => item.Fxi),
        backgroundColor: 'rgba(75, 192, 192, 0.2)',
        borderColor: 'rgba(75, 192, 192, 1)',
        borderWidth: 1,
      }]
    };

    const chartOptions = {
      scales: {
        xAxes: [{
          scaleLabel: {
            display: true,
            labelString: 'Iteration',
          },
        }],
        yAxes: [{
          scaleLabel: {
            display: true,
            labelString: 'F(xi)',
          },
        }],
      },
    };

    if (chartRef && chartRef.current) {
      const ctx = chartRef.current.getContext('2d');
      new Chart(ctx, {
        type: 'line',
        data: chartData,
        options: chartOptions,
      });
    }
  }, [data]);

  return <canvas ref={chartRef} />;
};

export default ChartComponent;
