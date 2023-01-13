const canvas = document.getElementById("canvas");
const pen = canvas.getContext("2d");
let gameSpeed = 150;
const cs = 67;
const W = 1200;
const H = 735;
let gameOver = true;
let max_score = 0;
let food = null;
let score = 0;
let id = null;
let easy = document.querySelector(".easy");
let medium = document.querySelector(".medium");
let hard = document.querySelector(".hard");
let reset = document.querySelector(".reset");

let snake = {
  len: 5,
  direction: "Right",
  cells: [],
  createSnake: function () {
    for (let i = 0; i < this.len; i++) {
      this.cells.push({
        x: i,
        y: 0,
      });
    }
  },
  drawSnake: function () {
    pen.fillStyle = "orange";
    pen.fillRect(
      this.cells[this.cells.length - 1].x * cs,
      this.cells[this.cells.length - 1].y * cs,
      cs - 1,
      cs - 1
    );
    pen.fillStyle = "yellow";

    for (let i = 0; i < this.cells.length - 1; i++) {
      pen.fillRect(this.cells[i].x * cs, this.cells[i].y * cs, cs - 1, cs - 1);
    }
  },
  updateSnake: function () {
    let old_x = this.cells[this.cells.length - 1].x;
    let old_y = this.cells[this.cells.length - 1].y;
    if (old_x == food.x && old_y == food.y) {
      score++;
      food = getRandomFood();
    } else {
      this.cells.shift();
    }
    if (this.direction == "Right") {
      // new_x += 1;
      this.cells.push({ x: old_x + 1, y: old_y });
    } else if (this.direction == "Left") {
      this.cells.push({ x: old_x - 1, y: old_y });
      // new_x -= 1;
    } else if (this.direction == "Up") {
      this.cells.push({ x: old_x, y: old_y - 1 });
      // new_y -= 1;
    } else if (this.direction == "Down") {
      this.cells.push({ x: old_x, y: old_y + 1 });
      // new_y += 1;
    }
    if (
      this.cells[this.cells.length - 1].x * cs >= W ||
      this.cells[this.cells.length - 1].y * cs >= H ||
      this.cells[this.cells.length - 1].x * cs < 0 ||
      this.cells[this.cells.length - 1].y * cs < 0
    ) {
      gameOver = true;
      // alert("Game Over");
    }
    this.selfBite();
  },
  selfBite: function () {
    let old_x = this.cells[this.cells.length - 1].x;
    let old_y = this.cells[this.cells.length - 1].y;
    for (let i = 0; i < this.cells.length - 1; i++) {
      if (this.cells[i].x == old_x && this.cells[i].y == old_y) gameOver = true;
    }
  },
};

function getRandomFood() {
  var food = {
    x: 0,
    y: 0,
  };
  food.x = Math.round((Math.random() * (W - cs)) / cs);
  food.y = Math.round((Math.random() * (H - cs)) / cs);
  // console.log(food.x, food.y);
  return food;
}

function init() {
  pen.clearRect(0, 0, W, H);
  snake.createSnake();
  food = getRandomFood();

  // snake.drawSnake();
  document.addEventListener("keydown", (e) => {
    // console.log(e.key);
    if (e.key == "ArrowUp" && snake.direction != "Down") {
      snake.direction = "Up";
    } else if (e.key == "ArrowDown" && snake.direction != "Up") {
      snake.direction = "Down";
    } else if (e.key == "ArrowRight" && snake.direction != "Left") {
      snake.direction = "Right";
    } else if (e.key == "ArrowLeft" && snake.direction != "Right") {
      snake.direction = "Left";
    }
    // console.log(snake.direction);
  });
}

function draw() {
  //   console.log("In Draw");
  if (gameOver) {
    pen.fillStyle = "red";
    pen.fillText(`Game Over`, 100, 110);
    reset.style.display = "block";
    easy.style.display = "none";
    medium.style.display = "none";
    hard.style.display = "none";
    document.querySelector("h1").innerText = "Reset the game to play again.";
    if (score > max_score) max_score = score;
    document.querySelector(".maxScore").innerText = `Max score = ${max_score}.`;
    clearInterval(id);
    return;
  }
  pen.clearRect(0, 0, W, H);
  pen.fillStyle = "yellow";
  pen.font = "40px sans-serif";
  pen.fillText(`Score: ${score}`, 100, 50);
  snake.drawSnake();
  pen.fillStyle = "blue";
  pen.fillRect(food.x * cs, food.y * cs, cs - 1, cs - 1);
  // if (gameOver) {
  //   pen.fillStyle = "red";
  //   pen.fillText(`Game Over`, 100, 110);
  //   reset.style.display = "block";
  //   clearInterval(id);
  // }
  // let food = getRandomFood();
}

function update() {
  snake.updateSnake();
  //   console.log("In Update");
}

function gameLoop() {
  // console.log(snake.cells);
  update();
  draw();

  // console.log("In Game Loop");
}

init();

//Game Mode selector + reset

easy.addEventListener("click", () => {
  if (!gameOver) return;
  gameSpeed = 200;
  // console.log(easy);
  gameOver = false;
  id = setInterval(gameLoop, gameSpeed);
});

medium.addEventListener("click", () => {
  if (!gameOver) return;
  // console.log(medium);
  gameSpeed = 125;
  gameOver = false;
  id = setInterval(gameLoop, gameSpeed);
});

hard.addEventListener("click", () => {
  if (!gameOver) return;
  // console.log(hard);
  gameSpeed = 100;
  gameOver = false;
  id = setInterval(gameLoop, gameSpeed);
});

reset.addEventListener("click", () => {
  snake.len = 5;
  snake.direction = "Right";
  snake.cells = [];
  gameOver = true;
  reset.style.display = "none";
  easy.style.display = "inline-block";
  medium.style.display = "inline-block";
  hard.style.display = "inline-block";
  document.querySelector("h1").innerText = "Select the level-";
  score = 0;
  // max_score = 0;
  init();
});
