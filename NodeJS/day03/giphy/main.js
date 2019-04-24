const input = document.querySelector('#js-userinput')
const button = document.querySelector('#js-go')
const resultArea = document.querySelector('#result-area')
const tvArea = document.querySelector('#tv-area')

const API_KEY = 'ca6434XaDdudJeioOqvblYqQatskcaaY'


// 1.인풋 안의 값을 잡는다.

input.addEventListener('keydown', event => {
    if (event.keyCode == 13) {
        const keyword = input.value
        console.log(keyword)
        searchAndPush(keyword)
    }
})

button.addEventListener('click', event => {
    const keyword = input.value
    console.log(keyword)
    searchAndPush(keyword)
})




// 2. Giphy API를 통해 data를 받아서 가공한다.
// https://developers.giphy.com/

const searchAndPush = keyword => {
    resultArea.innerHTML = null
    const URL = `https:/api.giphy.com/v1/gifs/search?q=${keyword}&api_key=${API_KEY}`
    const GiphyAJAXCall = new XMLHttpRequest()
    GiphyAJAXCall.open('GET', URL)
    GiphyAJAXCall.send()
    
    GiphyAJAXCall.addEventListener('load', event => {
        const rawData = event.target.response
        const parsedData = JSON.parse(rawData)
        for (const data of parsedData.data) {
            pushToDom(data.images.fixed_height.url)
        }
        // pushToDom(parsedData.data[0].images.fixed_height.url)

        let cnt = 0
        pushToDomTV(parsedData.data[cnt].images.fixed_height.url)
        setInterval(() => {
            cnt += 1; cnt %= 25
            pushToDomTV(parsedData.data[cnt].images.fixed_height.url)
        }, 1000)
    })
}




// 3. GIF 파일들을 HTML(DOM) 에 밀어 넣는다.

const pushToDom = data => {
    const gif = document.createElement('img') // <img></img>
    gif.src = data // <img src="${data}"/>
    resultArea.insertBefore(gif, resultArea.firstChild)
    // resultArea.appendChild(gif)
    // resultArea.innerHTML += `<img src="${data}"/>`
}

const pushToDomTV = data => {
    tvArea.innerHTML = `<img src="${data}"/>`
}