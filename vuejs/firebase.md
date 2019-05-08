## Firebase

> 모바일, 웹 앱 플랫폼

```
Project name
todo

Project ID
todo-ff43e

Analytics location
South Korea

Cloud Firestore location
asia-northeast1
```



- 과거엔 소프트웨어 판매 후 사후관리가 힘들었기 때문에 완성품을 유통
- 지금은 업데이트 매우 용이
- AB테스트(여러 버전을 동시에 관리해서 필요(사용자) 데이터 수확 및 비교)


```html
<script src="https://www.gstatic.com/firebasejs/5.9.1/firebase.js"></script>
<script>
    // Initialize Firebase
    // TODO: Replace with your project's customized code snippet
    var config = {
        apiKey: "<API_KEY>",
        databaseURL: "https://todo-ff43e.firebaseio.com",
        projectId: "todo-ff43e",
    };
    firebase.initializeApp(config);
</script>
```


#### Vue fire
* Vue + firebase 연결


```html
<!-- Vue.js -->
<script src="https://cdn.jsdelivr.net/npm/vue@2.6.10/dist/vue.js"></script>
<!-- Vuefire -->
<script src="https://unpkg.com/vuefire/dist/vuefire.js"></script> 
<script>
    const db = firebase.database()
    const app = new Vue({
        el: '#app',
        data: {
            newTodo: '',
            // todos: [],
        },
        methods: {
            addTodo: function() {
                // this.todos.push(this.newTodo)
                this.$firebaseRefs.todos.push({
                    id: Date.now(),
                    content: this.newTodo,
                    completed: false
                })
                this.newTodo = ''
            },
            updateTodo: function(todo) {
                const newTodo = { ...todo } // spread operator: 객체복사
                delete newTodo['.key']
                this.$firebaseRefs.todos.child(todo['.key']).set(newTodo)
            }
        },
        // Vuefire properties
        firebase: {
            todos: db.ref('todos')
        }
    })
</script>
```