// 1. function 키워드를 통해 함수를 정의
function sum(a, b) {
    return a + b;
}

// 2. 익명함수 선언 => 변수에 할당 (중요)
let sum1 = function(a, b) {
    return a + b;
}
// sum => "function"(객체) => sum()

// ES6 arrow function
let sum3 = (a, b) => {
    return a + b;
}

// simpler
let sum4 = (a, b) => a + b;
let sum5 = a => a + 2;


/* 배열 순회
let menu = ["짜장면", "짬뽕", "쌈밥", "김밥"]

// 1. for문을 통해 배열 순회
for (let i = 0; i < menu.length; i++) {
    console.log(menu[i])
}

// 2. forEach() 메서드를 통해 순회
menu.forEach(function(food){
    console.log(food)
})
// arrow function
menu.forEach(food => {
    console.log(food)
})
*/