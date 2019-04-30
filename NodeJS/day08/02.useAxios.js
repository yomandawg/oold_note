// html에서 cdn으로 선언했기 때문에 바로 사용 가능
const URL = 'https://dog.ceo/api/breeds/image/random'
// axios.get(URL) // 비동기 요청 => .then
//     .then(response => { // .then으로 가져와야 함
//         const imageURL = response.data.message
//         const imgBox = document.querySelector('.img-box')
//         const img = document.createElement('img')
//         img.src = imageURL
//         imgBox.appendChild(img)
//     })


// TODO: use async await
const getImageUrl = async () => { // async 비동기 처리
    const response = await axios.get(URL) // axios 비동기 => await으로 가져올 수 있다
    const imageURL = response.data.message
    const imgBox = document.querySelector('.img-box')
    const img = document.createElement('img')
    img.src = imageURL
    imgBox.appendChild(img)
}

getImageUrl()