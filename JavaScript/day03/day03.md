# HTTP and API

#### REST 방식
> Representational State Transfer
* 웹기반 architecture
* HTTP 위에서 작동하는 규약 중 하나

#### HTTP 기본 속성
* 브라우저 요청이 기본적으로 GET, url로 GET method밖에 보내지 못함
* Stateless
    - 클라이언트가 서버와 상호작용을 위해 HTTP 쿠키를 만들고, 상태가 있는 세션을 활용할 수 있도록 보완
    - 상태정보가 저장되지 않음(요청 사이에 연결고리가 없음)

* Connectless
    - 서버에 요청을 하고 응답을 한 후 연결은 끊어짐

#### URL (Uniform Resource Locator)
* 웹서비스 내에서 주문서
    - 양식이 너무 다양해


#### DOM (Document Object Model)
* 브라우저가 HTML페이지를 인식하는 방식
* document 객체와 관련된 객체의 집합
* 구조화된 문서를 표현하는 방식 - Tree 자료구조


### REST
* URL, 요청 주소의 약속

#### 중심 규칙
1. URI는 정보의 자원(data record)을 표현해야 한다.
    - URI에선 동사를 표현하지 않는다
2. 자원에 대한 행위는 HTTP Method로 표현한다.
    * CREATE
        - `/posts` POST
    * READ
        - `/posts/<path_variable>` GET
    * UPDATE
        - `/posts/<path_variable>` PUT
    * DELETE
        - `/posts/<path_variable>` DELETE
    ```
    GET	/posts
    GET	/posts/1
    GET	/posts/1/comments
    GET	/comments?postId=1
    GET	/posts?userId=1
    POST	/posts
    PUT	/posts/1
    PATCH	/posts/1
    DELETE	/posts/1
    ```
    - `/`는 계층구조로만; `Django`는 /사용해서 half-restful
    - static 페이지는 어쩔 수 없음
    - ex) `fifa.com/worldcup/players/player/307753/profile`
        - 리소스 관계에 동사를 넣지 않는다


#### XML
* JSON 이전에 data 주고받기 형식
* 데이터 표현 key-value를 DOM 형식으로 전달
* 요즘엔 JSON이 지배적인 파일 형태를 받는 용도

#### YAML
* YAML ain't Markup Language
* supplementary for XML problems
* easier lookup of key-value pair

#### JSON
* easir use of key-value pair



#### JS Features
* Non-blocking
    - 위 함수가 안끝나도 기다리지 않고 다음 것으로 넘어가
    - Event Loop: 이게 끝나는지 안끝나는지 계속 check하는 함수
* asynchronous
    - 비동기적(순서대로 x)

* JS multi-thread 아니고 single-thread이므로 대체로 non-blocking 사용
    - 언어가 event loop을 통해 single-thread로도 다 관리해줌
        - JS가 편리한 이유

* linux std time
    - 1970:00:00:00 UTC 기준점