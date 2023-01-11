let url1 =
  "https://images.unsplash.com/photo-1672167631481-8b1171d2aad2?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1128&q=80";
let url2 =
  "https://images.unsplash.com/photo-1672572305595-c0a319dc09f3?ixlib=rb-4.0.3&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80";

let interval = true;
let img = document.querySelector("img");
function myFun() {
  if (interval) {
    img.setAttribute("src", url1);
    interval = false;
  } else {
    img.setAttribute("src", url2);
    interval = true;
  }
  //   interval = !interval;
}

setInterval(myFun, 2000);
