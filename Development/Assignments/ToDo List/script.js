let btn = document.querySelector("button");
// console.log(btn);
let task = document.querySelector("input");
// console.log(task.value);
let list = document.querySelector("p");
// console.log(task);

function myFun() {
  let t = task.value;
  console.log(t);
  let new_task = document.createElement("p");
  new_task.innerText = t;
  list.append(new_task);
  task.value = "";
  new_task.addEventListener("click", () => {
    new_task.remove();
    // console.log(item);
  });
}

btn.addEventListener("click", myFun);
//lOGIC FOR WORKING WITH ENTER BUTTON
task.addEventListener("keydown", (e) => {
  if (e.key == "Enter") myFun();
});

// btn.addEventListener("keypress", myFun(e));
