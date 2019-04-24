// Ajax 요청 구현

// XMLHttpRequest: 외부 네트워크 리소스를 불러오는 객체
const XHR = new XMLHttpRequest() // new: 새로운 객체를 만듦
const URL = 'https://koreanjson.com/posts/1'

XHR.open('GET', URL)
XHR.send()

XHR.addEventListener('load', event => {
    const rawData = event.target.response // return json string
    const parsedData = JSON.parse(rawData) // string => data
    console.log(parsedData)
})