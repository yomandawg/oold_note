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





