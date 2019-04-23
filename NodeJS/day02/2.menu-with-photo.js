var _ = require('lodash') // import lodash

var menus = ['짜장', '짬뽕', '볶음'] // Array, string convention single quote(')
var pick = _.sample(menus)
console.log(`메뉴는 ${pick}`) // 동적 string 출력: template literal

// js object ~ python dictionary: key-value
var object = {
    짜장: 'image1',
    짬뽕: 'image2',
    볶음: 'image3', // trailing comma: convention
}
console.log(object[pick])