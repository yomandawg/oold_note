// hoisting 가능
console.log(sum(1, 2))

function sum(a, b) {
    return a + b
}

// lambda
const sum2 = function (a, b) {
    this // 실행 시점의 객체를 바라보게 됨
    return a + b
}

// lambda with arrow
const sum3 = (a, b) => {
    this // 선언 시점의 객체를 바라보게 됨
    return a + b
}

const sum4 = (a, b) => a + b

console.log(sum2(1, 2))
console.log(sum3(1, 2))
console.log(sum4(1, 2))
