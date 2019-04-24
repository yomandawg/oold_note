// axios (javascript version of python requests)

const URL = "https://jsonplaceholder.typicode.com/"

// new: 생성자
const XHR = new XMLHttpRequest()

// (HTTP 메소드, URL)
XHR.open('POST', URL + 'posts')

// API에 어떤 데이터를 날리는지 header에 알려야함
XHR.setRequestHeader(
    'Content-Type',
    'application/json;charset=UTF-8' // 파일형식;encoding
)

const data = {
    userId: 1,
    title: "제목이다",
    body: "ㅈㄱㄴ"
}

// 데이터
XHR.send(JSON.stringify(data)) // object to string

XHR.addEventListener('load', function(e){
    const result = e.target.response
    console.log(result)
})