console.log(process.argv);
const arr = process.argv.slice(2);
console.log(arr);

for (let a of arr) {
  for (let i = 1; i <= a; i++) {
    let t = false;
    if (i % 3 == 0) {
      console.log("FIZZ ");
      t = true;
    }
    if (i % 5 == 0) {
      t = true;
      console.log("BUZZ");
    }
    if (!t) console.log(i);
  }
}
