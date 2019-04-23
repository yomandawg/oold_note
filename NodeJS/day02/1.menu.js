// 1.menu.js
var _ = require('lodash') // import lodash

var menus = ['짜장면', '짬뽕', '볶음밥',] // Array
// console.log(menus)

var pick = _.sample(menus) // random 한 개
console.log(pick)

// alert() // browser function 작동 안함