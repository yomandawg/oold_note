// axios (javascript version of python requests)

const URL = "https://jsonplaceholder.typicode.com/"

// new: 생성자
const XHR = new XMLHttpRequest()

// HTTP 메소드 PUT
XHR.open("PUT", URL + 'posts/1')

// API에 어떤 데이터를 날리는지 header에 알려야함
XHR.setRequestHeader(
    'Content-type',
    'application/json;charset=utf-8'
)

const data = {
    userId: 1,
    title: "수정한 것",
    body: "수정바디"
}

// 데이터
XHR.send(JSON.stringify(data)) // object to string

XHR.addEventListener('load', function(e){
    const result = e.target.response
    console.log(result)
})