// ------- XHR 사용하기 귀찮아 --------
// XML: JSON 이전에 data주고받기 형식
// const XHR = new XMLHttpRequest()
// XHR.addEventListener()
// ------- XHR 사용하기 귀찮아 --------


const URL = "https://jsonplaceholder.typicode.com/posts"


// XHR 대안 fetch()
const res = fetch(URL).then(function(response) { // 요청.pending(whatToDO)
    return response.json()
})

res.then(function(obj) {
    console.log(obj)
})



// 익명 함수 만들기
const myFunc1 = function (input) {
    return input
}
// arrow function
const myFunc2 = (input) => {
    return input
}
// if 1 input
const myFunc3 = input => {
    return input
}
// if 1 line return
const myFunc4 = input => input



// 간결화
fetch(URL).then(response => response.json())
res.then(obj => obj)

// chaining
const res_chain = fetch(URL).then(response => response.json()).then(obj => obj)

console.log(res_chain)