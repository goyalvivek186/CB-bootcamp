class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  say_name() {
    console.log(`Hi ${this.name}`);
  }
}

const p1 = new Person("Vivek", 21);
const p2 = new Person("Sabeel", 22);
