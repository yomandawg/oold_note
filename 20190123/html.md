# CSS

> **cascading style sheet**

```html
<style>
    ul {
        margin-top: 16px;
    }
    li {
        display: inline;
    }
</style>
```



#### 구체화 순서

1. !important
2. Inline tag
3. #id
4. .class
5. Tag 이름
6. 글로벌



#### 선언 순서

1. 무조건 뒤에 정의된 친구가 적용
2. 





## Display

> 항상 어떤 Display 형태로 출력되고 있는지 염두해야함



### Block elements

> 항상 새로운 라인에서 시작한다. 화면 크기 전체의 가로폭을 차지한다. (default style="width:100%")
>
> block level 내의 요소는 

* `<h1>` 



### Inline elements

> 새로운 라인에서 시작하지 않으며 문장의 중간에 들어갈 수 있다.
>
> content의 너비만큼 가로폭을 차지한다.
>
> no "width", "height", "margin-top", "margin-bottom" properties
>
> margin can be situated with "line-height", "margin-left", "margin-right"
>
> **no returning errors**

* `<a>`
* `<span>`



### Inline-block

> block과 inline 레벨 요소의 특징을 모두 가진다.
>
> inline 레벨 요소처럼 한 줄에 표시되면서
>
> block의 width...를 특징을 가진다.



### None

>해당 요소를 화면에 표시하지 않는다.
>
>`visibility: hidden` 은 공간은 차지하지만 none은 공간도 차지하지 않는다.

* Visibility
  * hidden, visible







----

## HTML cheat sheet

`"ul>li*3" + tab`





### Color visualization

`https://www.color-hex.com/`



### Free Fonts

`https://fonts.google.com/`



*customize* : `chrome settings: fonts`

 * not shown to other people



simple: `spoqa han sans`



```
git credential reject
protocol=https
host=lab.ssafy.com
```

