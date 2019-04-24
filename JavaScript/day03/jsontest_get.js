// axios (javascript version of python requests)

const URL = "https://jsonplaceholder.typicode.com/"

// new: 생성자
const XHR = new XMLHttpRequest()

// (HTTP 메소드, URL)
XHR.open('GET', URL + 'posts')
XHR.send()

// EventListener 보내기 가능
XHR.addEventListener('load', function(jik) { // 'load'일 때 function 해라: callback 형태
    const result = jik.target.response // XHR로 받은 response
    // console.log(result)
    const jsObject= JSON.parse(result) // object로 변환 - 배열
    // console.log(jsObject)
    const jsonString = JSON.stringify(jsObject) // string object으로 변환
    // console.log(jsonString)
    console.log(jsObject[0]) // index 접근 가능
})

// 1. JSON: string (js object 형태와 유사한)
//      - object로 변환 (JSON.parse())
// 2. Javascript Object: object
//      - JSON 파일(string) (JSON.stringify())
