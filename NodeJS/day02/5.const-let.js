// 블럭단위 스코프
// let => 재할당이 가능한, 변경 가능한 변수
// const => 재할당이 불가능한, 변경 불가능한 상수

// 함수단위 스코프
// var => 

// 상위 스코프에서 선언된 변수는 하위 스코프에서 접근 가능

if (true) {
    var message = 'ㅎㅇ'
    message = 'asdf' // 재할당 가능
}
console.log(message) // var 함수단위 스코프에서 사용 가능

if (true) {
    let converse = 'ㅎㅇ'
    converse = 'ㅁㄴㅇㄹ' // 재할당 가능
}
// console.log(converse) // let, const 블록단위 스코프에서만 사용 가능

let count = 0
count = count + 1 // 재할당 가능

const name = '요맨'
// name = 'john' // typeerror const 재할당 불가

const getMinFromArray = (numbers) => {
}