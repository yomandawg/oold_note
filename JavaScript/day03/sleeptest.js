function shinun() {
    // setTimeOut(function, time)
    setTimeout(()=>{console.log('쉬는시간')}, 5000) // similar to sleep() in python
}

// JS non-blocking (기다리지 않는다)
// 몇몇 함수 asynchronous (비동기적, 순서대로 x)
// 끝나기 안기다려줌
console.log('start')
shinun()
console.log('end')



// function sleep(sec) {
//     let start = Date.now()
//     // 이렇게 할 경우 뒤에 있는 operation을 그냥 blocking하므로
//     // 일반 sleep()에선 non-blocking으로 넘어감
//     while (Date.now() < start + sec*1000) {
        
//     }
// }

// function shinun() {
//     sleep(5)
//     console.log('쉬는시간')
// }

// console.log('쉬는시간 3초전')
// shinun()
// console.log('쉬는시간 끝')
