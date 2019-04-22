# javascript

> browser을 조작할 수 있게 하기 위해 만듦
>
> 되게 다양한 javascript version이 있음 - open source
>
> 회사마다 약간씩 다른 syntax, api를 사용



* IE - Netscape 베낌
* Netscape정신 - Mozilla



* Browser을 조작할 수 있게 만든 언어 - browser에서 실시간 디버깅 가능



* ECMA
  * 국제 표준화 기구 - JavaScript



* BOM - Browser Object Model(브라우저 조작)

`window.print()`

`window.innerWidth` `window.innerHeight`

`window.document.title` `window.document.title='asdf'` - 브라우저의 문서도 조작 가능

`if (age>20) { alert('dasdf') }`



```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
    
<script>
// console.log()
document.write('<h1>asdfsadf</h1>') // 태그를 함께 넣을 수 있다.
document.write('<p>qweqwtqw</p>')
</script>

</body>
</html>
```

`console.log()` - 콘솔 로그

`document.write('asdfs')` - write

페이지를 띄우고 script를 실행하고



* 프로그래밍 언어
  * 저장
  * 조작 - 조건, 반복



* javascript 원시자료형(primitive data type) &rarr; immutalbe

    1. string

    2. number

    3. boolean

    4. null - 원래는 없었던 자료형이라 하위호환되기 위해 object로 표시

    5. undefined
    
    * `console.log(typeof("hello"))`

* 원시자료형 제외 모든 것이 객체(사용자 정의 자료형, Array, Function, Object all of them are objects) &rarr; (im)mutable
  * `"가나다라마바사".length`
  * `tuple` `string` immutable, else mutable



```js
const name = 'ray'
name = 'dongju' // time-error (constant not changeable)

let age = '27'
age = '28' // age binded to 28
```

* `const` - 변화 불가능
* `let` - 변화 가능



`for (초기조건, 종료조건, 증강식)`

```js
for (var i = 0; i < 10; i++) {
    console.log(i)
}
/*
for var
output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
i = 10; // 조건이 끝난 다음에 증감
*/
for (let j = 0; j < 10; j++) {
    console.log(j)
}
/*
for let
output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
j doesn't exist // j 소멸
*/
for (const z=0; z<10; z++){ // can't do
    console.log(z)
}
```



```js
names = ["ray", "ash"]
names.length // 길이
names.reverse() // 뒤집기
names.push("jik") // append
names.pop() // "jik"
names.shift() // popleft()
names.unshift() // insert(0, item)
names.include('jik') // True or False
names.join("와 ") // string화해서 "asdf와 B와 A" different from python join
["john", 123, true, [1,2,3]] // (4) ["john", 123, true, Array(3)]
```



```js
// dictionary
const student = {'name': 'john', 'age': 20, 'isMale': true}
student['name'] // "john" == student.get('name')

const student2 = {name:'john', age:20, isMale:true} // key string으로 안해도 됨
student2["name"] // 'john'
student2.name // 'john'
```



```js
let i = 0;
while (i < 10) {
    console.log(i);
    i += 1;
} // loop: asynchronous needed
```

```js
if (age > 30 ) {
    console.log('asdf');
} else if (age < 20) {
    console.log('eeee');
} else {
    console.log('asdfdeee');
}
```



```js
function sum(a, b) {
    return a+b
}
sum(3, 5) // 8
```

```js
firstName = 'asdf'; lastName = 'ererw';
let fullName = firstName + lastName; // string concatenation
let introduction = 'ㅎㅇ 저는 ${firstName} ${lastName}'; // string inerpolator
```



```js
const me = {
    bane: 'john',
    phone: '01234',
    apple: {
        iPad: '2018pro',
        iPhone: '6s+',
        macBook: '2018pro',
    }
}
me.address = "강남구" // 객체는 mutable
me.apple.yo = 'asdf'
me // {bane: "john", phone: "01234", apple: {…}, address: "강남구"}
```

