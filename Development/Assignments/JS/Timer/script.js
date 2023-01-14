let inp = document.querySelector("input");
let btns = document.querySelectorAll("button");
let start = btns[0];
let reset = btns[1];

let time = 0;
let ts = true;
let id = null;
let min = 0;
let timer;
let counter = 60;
// inp.value = "0";
function start_timer() {
  console.log("Time is Running");
  counter--;
  inp.value = `${min} m: ${counter} s`;
  if (counter == 0) {
    //1min = 60sec
    if (min != 0) min--;
    console.log("1Min");
    if (min == 0 && counter == 0) {
      resetTimer();
      ts = false;
      console.log("Clear Interval");
      clearInterval(id);
    }
    counter = 60;
  }
}

function resetTimer() {
  min = 0;
  time = 0;
  counter = 60;
  inp.value = "0";
  start.innerText = "Start";
  clearInterval(id);
}

function init() {
  if (ts) {
    console.log("Time starts NOW!!");
    if (time == 0) {
      if (inp.value == "" || inp.value == 0) {
        resetTimer();
        // time = 0;
      } else {
        min = Number(inp.value) - 1;
        // if (Number(inp.value) === NaN) {
        //   alert("Please Enter a valid time.");
        //   resetTimer();
        //   return;
        // }
        console.log(min, "Minutes");
        time = 1;
        time = min * 60 * 1000;
        // console.log();
        console.log("ms", time);
        timer = time;
      }
    }
    // console.log(time);
  } else {
    console.log("Time Over");
  }
}

function main() {
  if (start.innerText == "Start") {
    //time start = true;
    init();
    if (time <= 0) return;
    console.log("Starting Timer");
    start.innerText = "Stop";
    id = setInterval(start_timer, 1000);
  } else {
    console.log("In else");

    // id = null;
    start.innerText = "Start";
    clearInterval(id);
  }
}

// start.addEventListener("click", () => {
// if (start.innerText == "Start") {
//   //time start = true;
//   init();
//   if (time <= 0) return;
//   console.log("Starting Timer");
//   start.innerText = "Stop";
//   id = setInterval(start_timer, 1000);
// } else {
//   console.log("In else");

//   // id = null;
//   start.innerText = "Start";
//   clearInterval(id);
// }
// });
start.addEventListener("click", main);

reset.addEventListener("click", resetTimer);

// Working with Enter Key
inp.addEventListener("keydown", (e) => {
  // console.log(e.key);
  if (e.key == "Enter") main();
});
