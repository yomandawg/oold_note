# HTML

```html
<!DOCTYPE html> # html인걸 빠르게 알려줌
<head>
    <meta>
</head>

<body>
    브라우저 화면에 나타나는 정보로 실제 내용에 해당
</body>
```



## Tag

* HTML의 element는 태그와 내용(contents)로 구성되어 있다.

```html
<h1> # 태그
    웹 문서
</h1>
태그는 대소문자를 구별하지 않으나, 소문자로 작성해야 한다.
요소간의 중첩도 가능하다

<img src='url'/> # Self.closing element
닫는 태그가 없는 태그도 존재한다.(자체닫음: 없어도 되는데 넣어주는 습관 들이자)

id, class style은 태그와 상관없이 모두 사용가능하다.

<a href='google.com'/> # attribute 태그(속성이 지정될 수 있다.)
   속성명  속성값
href(hyper reference): 링크로 가게하게끔(속성값이 key 느낌)

CSS로 조절하기 위해 사용하는 (의미없는 형식의) tag들:
<div> # 디비젼
    블럭 요소, 레이아웃 잡는 용도
</div>

<span>
	인라인 요소
</span>

```

### 시맨틱(sementic) 태그

* **컨텐츠의 의미를 설명**하는 태그로서, HTML5에 새롭게 추가됨
* 미적 감각 / 컨텐츠 배치 / user-friendly
* DOM TREE에서 관리하기 쉽게 만듦

```html
<header> 헤더(전체 문서의 헤더)
<nav> 네비게이션(페이지 탐색할 수 있는 바)
<aside> (blog같은 곳에서 사이드 바)
<section> article 형식의 틀 관리 (여러개의 section을 통해 배치 균형 맞춤)
    # Grid System
<article> section 안의 하나의 문서 관리
<footer> aside의 하단부 또는 완전 하단부
등등..
```

* 개발자 및 사용자 뿐만 아니라 검색엔진 등에 의미있는 정보의 그룹을 태그로 표현하여 단순히 보여주게 하기 위해 씀



## DOM TREE

* Browser이 문서를 정리하는 방법(자료구조)
  * (Document Object Model) Tree형태
* 태그들을 object형태(객체화) 트리로 구조화해서 관리함
  * -> 각각의 객체가 어디있는지 알기 때문에 찾기 쉬움

```html

```







