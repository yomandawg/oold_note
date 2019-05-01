// https://www.themoviedb.org/

const API_KEY = "3289d6539106d618dcdd96900bf7c5d0"
const URL = `https://api.themoviedb.org/3/movie/popular?api_key=${API_KEY}`
const IMG_URL = 'http://image.tmdb.org/t/p/w200'

// axios.get(URL)
//     .then(response => {
//         // console.log(response.data)
//         const movies = response.data.results
//     })



// const startApp = async function () { // const 함수형 hoisting 불가능

//     const response = await axios.get(URL)
//     const movies = response.data.results

//     // array의 item을 callback에서 return하는 값으로 바꾼 새로운 array를 반환함
//     const newMovies = movies.map(movie => {
//         return {title: movie.title , image: IMG_URL+movie.poster_path}
//     })

//     const demo = new Vue({
//         el: '#main',
//         data: {
//             searchString: '',
//             movies: newMovies,
//         },
//         methods: {

//         },
//         // 결과값을 caching해서 vue instance가 사용할 수 있게 해줌
//         computed: {
//             filteredMovies: function() {
//                 let movies_array = this.movies
//                 let searchString = this.searchString

//                 if (!searchString) { // 만약 searchString이 아무것도 없으면
//                     return movies_array
//                 }

//                  // 키워드로 sorting한 영화가 return이 되도록
//                 searchString = searchString.trim().toLowerCase() // 공백 지워주고 소문자로
//                 movies.array = movies_array.filter(movie => {
//                     // movie.title에 searchString이 포함되면 반환
//                     return movie.title.toLowerCase().includes(searchString)
//                 })
//                 return movies.array
//             }
//         },
//     })
// }




// simplified version
const app = new Vue({
    el: '#main',
    data: {
        searchString: '',
        movies: [],
    },
    computed: {
        filteredMovies: function () {
            if (!this.searchString) {
                return this.movies
            }

            let searchString = this.searchString.trim().toLowerCase()
            return this.movies.filter(movie => {
                return movie.title.toLowerCase().includes(searchString)
            })
        }
    },
    // Vue 인스턴스가 초기화 되고나서 실행하는 함수
    // 1. 빈 무비 데이터를 가지고 있는 Vue 인스턴스가 만들어진다.
    // 2. completed 함수가 실행되면서 movies를 불러온다.
    // 3. 불러온 movies를 vue의 data안의 movies에 할당한다.
    async created() {
        const response = await axios.get(URL)
        this.movies = response.data.results.map(movie => {
            return { title: movie.title, image: IMG_URL + movie.poster_path }
        })
    }
})