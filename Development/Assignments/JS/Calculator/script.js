let screen = document.getElementsByClassName("screen")[0];
// console.log(screen);
let btns = document.querySelectorAll("button");
// console.log(btns);

let eqn = "";
function myFun(e) {
  let b = e.target.innerText;
  //   console.log(b);
  //   console.log(eqn);
  if (b == "C") {
    eqn = "";
    screen.value = eqn;
  } else if (b == "X") {
    eqn += "*";
    screen.value = eqn;
  } else if (b == "=") {
    try {
      let ans = eval(eqn);
      screen.value = ans;
      eqn = "";
    } catch (error) {
      screen.value = "INVALID OPERATION";
      console.log(error);
      eqn = "";
    }
  } else {
    eqn += b;
    screen.value = eqn;
  }
}

for (let btn of btns) {
  btn.addEventListener("click", myFun);
}
