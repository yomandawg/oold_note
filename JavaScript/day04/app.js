// function shinun() {
//     setTimeout(() => {
//         console.log("쉬는 시간입니다")
//     }, 5000)
//     return "이건 랜덤이지"
// }

// console.log('asdf')
// const ret = shinun()
// console.log(ret)
// console.log('agdf')


// readfile() // 비동기적
const readFile = myFunc => {
    let content
    // 파일을 읽어오는데 100ms 소요
    setTimeout(() => {
        content = "Hello World"
        myFunc(content) // callback 함수 안에서 불리게 됨
    }, 100)
    return content
}

const log = content => console.log(content)

// function yo (content) {
//     console.log(content)
// }

readFile(log) // readFile(파일을 읽은 후에 실행할 내용)