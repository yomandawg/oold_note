// axios (javascript version of python requests)

const URL = "https://jsonplaceholder.typicode.com/"

// new: 생성자
const XHR = new XMLHttpRequest()

// HTTP 메소드 DELETE
XHR.open("DELETE", URL + 'posts/1')
XHR.send()

XHR.addEventListener('load', function(e){
    const result = e.target.response
    console.log(result)
})