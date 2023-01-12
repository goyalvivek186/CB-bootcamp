let btn = document.querySelector(".btn");
// console.log(btn);

let inp = document.querySelector("#inp");
// console.log(inp);

btn.addEventListener("click", () => {
  let task = inp.value;
  console.log(task);
});

inp.addEventListener("keydown", (e) => {
  console.log("Pressed", e.key);
  if (e.key == "Enter") console.log("Enter pressed");
});

// function myFun(a, b) {
//   console.log("Fuction Called", a, b);
// }

// setInterval(myFun, 2000, 5, 10);
