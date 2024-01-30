const fs = require('fs');

const os = require('os');

// // This was a Synchronous Call ->./ ->Current Directory ke andar
// // Blocking
// fs.writeFileSync('./test.txt', 'Hello World')


// // Non-Blocking
// // Asynchronous+Call Back Func
// fs.writeFile('./testA.txt', 'Hello Coders', (err) => { })


console.log("1")

// Blocking
// const result = fs.readFileSync("test.txt", "utf-8");

// Non-Blocking
const result = fs.readFile("test.txt", "utf-8", (err, result) => {
    console.log(result)

})



console.log("2")

console.log(os.cpus().length)