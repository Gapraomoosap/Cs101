fetch('data.csv')
  .then(response => response.text())
  .then(csvData => {
    // Parse the CSV data using PapaParse
    const parsedData = Papa.parse(csvData, { header: true }).data;

    // Count the number of occurrences of "bad" in the "Alignment" column
    let M_bad = 0, DC_bad = 0, ETC_bad = 0, M_male = 0, M_female = 0, M_other = 0;
    let M_good = 0, DC_good = 0, ETC_good = 0, DC_male = 0, DC_female = 0, DC_other = 0;
    let M_neutral = 0, DC_neutral = 0, ETC_neutral = 0, ETC_male = 0, ETC_female = 0, ETC_other = 0;
    let Eye_black = 0;
    let Eye_blue = 0;
    let Eye_brown = 0;
    let Eye_white = 0;
    let Eye_red = 0;
    let Eye_yellow = 0;
    let Eye_green = 0;
    let Eye_etc = 0;
    for (let i = 0; i < parsedData.length; i++) {
      if (parsedData[i]["Alignment"] === "bad" && parsedData[i]["Publisher"] === "Marvel Comics") {
        M_bad++;
      }
      else if (parsedData[i]["Alignment"] === "good" && parsedData[i]["Publisher"] === "Marvel Comics") {
        M_good++;
      }
      else if (parsedData[i]["Alignment"] === "neutral" && parsedData[i]["Publisher"] === "Marvel Comics") {
        M_neutral++;
      }
      else if (parsedData[i]["Alignment"] === "bad" && parsedData[i]["Publisher"] === "DC Comics") {
        DC_bad++;
      }
      else if (parsedData[i]["Alignment"] === "good" && parsedData[i]["Publisher"] === "DC Comics") {
        DC_good++;
      }
      else if (parsedData[i]["Alignment"] === "neutral" && parsedData[i]["Publisher"] === "DC Comics") {
        DC_neutral++;
      }
      else if (parsedData[i]["Alignment"] === "bad" && parsedData[i]["Publisher"] !== "DC Comics" && parsedData[i]["Publisher"] !== "Marvel Comics") {
        ETC_bad++;
      }
      else if (parsedData[i]["Alignment"] === "good" && parsedData[i]["Publisher"] !== "DC Comics" && parsedData[i]["Publisher"] !== "Marvel Comics") {
        ETC_good++;
      }
      else if (parsedData[i]["Alignment"] === "neutral" && parsedData[i]["Publisher"] !== "DC Comics" && parsedData[i]["Publisher"] !== "Marvel Comics") {
        ETC_neutral++;
      }
    }
    for (let i = 0; i < parsedData.length; i++) {
      if (parsedData[i]["Gender"] === "Male" && parsedData[i]["Publisher"] === "Marvel Comics") {
        M_male++;
      }
      else if (parsedData[i]["Gender"] === "Female" && parsedData[i]["Publisher"] === "Marvel Comics") {
        M_female++;
      }
      else if (parsedData[i]["Gender"] === "Other" && parsedData[i]["Publisher"] === "Marvel Comics") {
        M_other++;
      }
      else if (parsedData[i]["Gender"] === "Male" && parsedData[i]["Publisher"] === "DC Comics") {
        DC_male++;
      }
      else if (parsedData[i]["Gender"] === "Female" && parsedData[i]["Publisher"] === "DC Comics") {
        DC_female++;
      }
      else if (parsedData[i]["Gender"] === "Other" && parsedData[i]["Publisher"] === "DC Comics") {
        DC_other++;
      }
      else if (parsedData[i]["Gender"] === "Male" && parsedData[i]["Publisher"] !== "DC Comics" && parsedData[i]["Publisher"] !== "Marvel Comics") {
        ETC_male++;
      }
      else if (parsedData[i]["Gender"] === "Female" && parsedData[i]["Publisher"] !== "DC Comics" && parsedData[i]["Publisher"] !== "Marvel Comics") {
        ETC_female++;
      }
      else if (parsedData[i]["Gender"] === "Other" && parsedData[i]["Publisher"] !== "DC Comics" && parsedData[i]["Publisher"] !== "Marvel Comics") {
        ETC_other++;
      }
    }
    for (let i = 0; i < parsedData.length; i++) {
      if (parsedData[i]["Eye color"] === "black") {
        Eye_black++;
      } else if (parsedData[i]["Eye color"] === "blue") {
        Eye_blue++;
      } else if (parsedData[i]["Eye color"] === "brown") {
        Eye_brown++;
      } else if (parsedData[i]["Eye color"] === "white") {
        Eye_white++;
      } else if (parsedData[i]["Eye color"] === "red") {
        Eye_red++;
      } else if (parsedData[i]["Eye color"] === "yellow") {
        Eye_yellow++;
      } else if (parsedData[i]["Eye color"] === "green") {
        Eye_green++;
      }
      else{
        Eye_etc++;
      }
    }
    
    let M_total = M_bad + M_good + M_neutral, D_total = DC_bad + DC_good + DC_neutral, Etc_total = ETC_bad + ETC_good + ETC_neutral;
    let All = M_total + D_total + Etc_total;
    const Member = document.getElementById('donut');
    if (Member) {
      const ctx = Member.getContext('2d');
      const MemberD = new Chart(ctx, {
        type: 'doughnut',
        data: {
          datasets: [
            {
              data: [M_total, D_total, Etc_total],
              backgroundColor: [
                'rgb(149,30,34)',
                'rgb(4,118,242)',
                'rgb(255, 205, 86)',
              ],
            },
          ],
          labels: ['Marvel', 'DC', 'Etc'],
        },
        options: {
          plugins: {
            datalabels: {
              formatter: (value) => {
                return value + '%';
              },
            },
            title: {
              display: true,
              text: 'Number of superhero',
              font: {
                size: 18,
                weight: 'bold'
              }
            }
          },
        },
      });
    } else {
      console.error('Canvas element with ID "donut" not found');
    }

    const canvas = document.getElementById('myChart');
    if (canvas) {
      const ctx = canvas.getContext('2d');
      const myChart = new Chart(ctx, {
        type: 'bar',
        data: {
          datasets: [
            {
              label: 'Male',
              data: [M_male, DC_male, ETC_male],
              backgroundColor: 'rgb(2,163,254)',
              borderColor: 'rgb(0, 0, 0)',
              borderWidth: 1,
            },
            {
              label: 'Female',
              data: [M_female, DC_female, ETC_female],
              backgroundColor: 'rgb(230,76,166)',
              borderColor: 'rgb(0, 0, 0)',
              borderWidth: 1,
            },
            {
              label: 'Other',
              data: [M_other, DC_other, ETC_other],
              backgroundColor: 'rgb(246,246,246)',
              borderColor: 'rgb(0, 0, 0)',
              borderWidth: 1,
            },
          ],
          labels: ['Marvel', 'DC', 'Etc'],
        },
        options: {
          scales: {
            y: {
              beginAtZero: true,
              ticks: {
                callback: function (value, index, values) {
                  return value;
                },
              },
            },
          },
          plugins: {
            legend: {
              display: true,
            },
            title: {
              display: true,
              text: 'Gender of Superheroes',
            },
          },
        },
      });
    }
    const canvas2 = document.getElementById('myChart2');
    if (canvas2) {
      const ctx2 = canvas2.getContext('2d');
      const myChart2 = new Chart(ctx2, {
        type: 'bar',
        data: {
          datasets: [
            {
              label: 'bad',
              data: [M_bad, DC_bad, ETC_bad],
              backgroundColor: 'rgb(0, 0, 0)',
              borderColor: 'rgb(0, 0, 0)',
              borderWidth: 1,
            },
            {
              label: 'good',
              data: [M_good, DC_good, ETC_good],
              backgroundColor: 'rgb(255, 255, 255)',
              borderColor: 'rgb(0, 0, 0)',
              borderWidth: 1,
            },
            {
              label: 'neutral',
              data: [M_neutral, DC_neutral, ETC_neutral],
              backgroundColor: 'rgb(197, 214, 216)',
              borderColor: 'rgb(0, 0, 0)',
              borderWidth: 1,
            },
          ],
          labels: ['Marvel', 'DC', 'Etc'],
        },
        options: {
          scales: {
            y: {
              beginAtZero: true,
              ticks: {
                callback: function (value, index, values) {
                  return value;
                },
              },
            },
          },
          plugins: {
            legend: {
              display: true,
            },
            title: {
              display: true,
              text: 'Alignment of Superheroes',
            },
          },
        },
      });
    }
    document.getElementById("Total_member").innerHTML = 'Total <br> <br>' + All;
    const data = {
      labels: ['Black', 'Blue', 'Brown', 'White', 'Red', 'Yellow', 'Green','Etc'],
      datasets: [{
        label: 'Eye Colors',
        data: [Eye_black, Eye_blue, Eye_brown, Eye_white, Eye_red, Eye_yellow, Eye_green,Eye_etc],
        backgroundColor: [
          'rgb(0, 0, 0)',
          'rgb(0, 0, 255)',
          'rgb(165, 42, 42)',
          'rgb(255, 255, 255)',
          'rgb(255, 0, 0)',
          'rgb(255, 255, 0)',
          'rgb(0, 128, 0)',
          'rgb(197, 214, 216)'
        ],
        hoverOffset: 4
      }]
    };
    

    const config = {
      type: 'pie',
      data: data,
      options: {
        plugins: {
          title: {
            display: true,
            text: 'Eye color',
            font: {
              size: 18,
              weight: 'bold'
            }
          }
        }
      }
    };

    const myChart = new Chart(
      document.getElementById('myChart3'),
      config
    );



  });
