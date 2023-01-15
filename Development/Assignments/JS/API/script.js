// let key = "71a3d14fbd354904bd2191812231501";
// example = http://api.weatherapi.com/v1/current.json?key=71a3d14fbd354904bd2191812231501&q=Delhi&aqi=no
// link = https://www.weatherapi.com/api-explorer.aspx

let inp = document.getElementById("inp");
// inp.
let form = document.querySelector("form");
let max, min, avg, cur, loc, time, date, country;
max = min = avg = cur = loc = time = date = country = null;
let fore = document.getElementsByClassName("fore")[0];
let reset = document.getElementsByClassName("reset")[0];
// console.log(data);

function print() {
  document.getElementsByClassName("container")[0].style.height = "425px";
  fore.style.display = "block";
  fore.innerText = "";
  fore.innerText = `Country: ${country}\n`;
  fore.innerText += `Location: ${loc}\n`;
  fore.innerText += `Date : ${date}\n`;
  fore.innerText += `Time : ${time}\n`;
  fore.innerText += `Current-Temp : ${cur} °C\n`;
  fore.innerText += `Max-Temp : ${max} °C\n`;
  fore.innerText += `Min-Temp : ${min} °C\n`;
  fore.innerText += `Avg-Temp : ${avg} °C\n`;
  reset.style.display = "block";
}

function getTemp() {
  fetch(
    `http://api.weatherapi.com/v1/forecast.json?key=71a3d14fbd354904bd2191812231501&q=${loc}&days=1&aqi=no&alerts=no`
  )
    .then((res) => {
      return res.json();
    })
    .then((data) => {
      console.log(data);
      loc = data.location.name;
      country = data.location.country;
      console.log(loc);
      //   console.log(data.forecast.forecastday[0].day);
      cur = data.current.temp_c;
      //   console.log(data.current.temp_c);
      max = data.forecast.forecastday[0].day.maxtemp_c;
      //   console.log(data.forecast.forecastday[0].day.maxtemp_c);
      min = data.forecast.forecastday[0].day.mintemp_c;
      //   console.log(data.forecast.forecastday[0].day.mintemp_c);
      avg = data.forecast.forecastday[0].day.avgtemp_c;
      //   console.log(data.forecast.forecastday[0].day.avgtemp_c);
      date = data.location.localtime.split(" ")[0];
      time = data.location.localtime.split(" ")[1];
      //   console.log(data.location.localtime);
      //   console.log(time);
      //   console.log(date);
      print();
    })
    .catch((err) => {
      console.log(err);
      alert("something went wrong");
      resetIt();
    });
}

form.addEventListener("submit", (e) => {
  e.preventDefault();
  loc = inp.value;
  //   console.log(loc);
  getTemp();
  //   console.log(e);
});

function resetIt() {
  fore.style.display = "none";
  fore.innerText = "";
  max = min = avg = cur = loc = time = date = country = null;
  reset.style.display = "none";
  inp.value = "";
  document.getElementsByClassName("container")[0].style.height = "130px";
}

reset.addEventListener("click", resetIt);
