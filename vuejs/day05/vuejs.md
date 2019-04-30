# Vue.js

#### CDN
* content delivery network
* Development vs. Production Mode

## Modern Web Frameworks
> SPA: single page application
> 대부분의 front-end frameworks

* 항상 `return`(or `redirect`)는 `HTTP` response
    - SPA: 하나의 페이지에서 모든 작업(javascript)을 하자!

* declarative - procedure, 선언형
* imperative - 명령형; 절차로 다 짠다

#### React
* 자유도 &uarr;
* 너무 많은 데이터가 오고가면 관리가 안돼서 간략화시키기 위해 시작

#### Angular
* 자유도 &darr;

#### Vue
* light
* 절차는 따지지 않고
* 무엇이냐만 정의
* 선언적(declarative) rendering - 하고싶은 것을 묘사만 하자
    - how to는 vue.js가 하겠다

```js
let app = new Vue({
      // 주어
      el: '#app',
      // 목적어
      data: {
        msg: '<h1>happy hacking</h1>',
        age: 34
      },
      // 서술어
      methods: {
        plus: function () {
          this.age += 1 // 객체의 data들을 지칭
        }
      }
    })
```
```console
app.$el
app.$data
app.plus() // method 실행
```


## MVVM
> M V C == M V VM
> M(model) V(view) VM(view model)
* Vue.js - VM만 조작
* 데이터를 직접 관리