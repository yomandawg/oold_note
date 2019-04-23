const posts = [
    {id: 1, title: "안녕"},
    {id: 2, title: "자바스크립트"},
    {id: 3, title: "브라우저 조작"},
]

// forEach를 통해 순회를 하여 id가 2번인
// post를 찾으세요.

posts.forEach(function(post){
    if (post.id === 2){
        console.log(post)
    }
})
posts.forEach((post)=>{ // similar to lambda
    if (post.id === 2){
        console.log(post)
    }
})

const images = [
    {height: 10, width: 30},
    {height: 20, width: 90},
    {height: 50, width: 40},
]
// images에 들어가 있는 이미지들의 넓이를 구해 area에 넣으세요
const area = [];

images.forEach(image => {
    area.push(image.height * image.width);
})
console.log(area)

const numbers = [1, 2, 3, 4, 5, 6]
let squaredNumbers = []
// // 1. squaredNumbers를 numbers의 요소들을 제곱한 숫자들의 배열로 만든다. (for)
// for (let i = 0; i < numbers.length; i++) {
//     squaredNumbers.push(numbers[i]**2);
// }
// console.log(squaredNumbers)

// 2. map() - return값 존재
// python: map(lambda x: x**2, numbers)
squaredNumbers = numbers.map(function(number){
    return number**2
})
console.log(squaredNumbers)


let users = [
    {id: 1, username: 'tony'},
    {id: 2, username: 'steve'},
    {id: 3, username: 'thor'},
    {id: 4, username: 'tony'}
]



// find
// username 'tony'인 첫 번째 사람을 찾는 코드
let tony = users.find(function(user){
    return user.username === 'tony'; // 첫 번째 tony 찾고 끝냄
})

console.log(tony)



// filter
// username 'tony'인 모든 사람을 찾는 코드
let tonys = users.filter(function(user){
    return user.username === 'tony';
})

console.log(tony)



// reject => 해당하는 조건이 아닌 요소들만 return
function reject(array, func) {
    return array.filter(function(user) {
        return !func(user)
    })
}

const not_tonys = reject(users, function(user) {
    return user.username === 'tony'
})

console.log(not_tonys)



// every => 모든 요소들이 충족되면 true, else false
const every_tony = users.every(function(user){
    return user.id < 5
})

console.log(every_tony)



// some => 어떤 요소가 있다면 true
const some_tony = users.some(function(user){
    return user.username === 'tony'
})

console.log(some_tony)