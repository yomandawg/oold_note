### Software Engineering

* 소프트웨어의 개발, 운용, 유지보수 등의 생명 주기 전반을 체계적이고 서술적이며 정량적으로 다루는 학문





### 서비스로서의 소프트웨어(SaaS)

- 소프트웨어 및 관련 데이터는 중앙에 호스팅되고 사용자는 웹 브라우저 등의 클라이언트를 통해 접속하는 형태의 소프트웨어 전달 모델이다. **주문형 소프트웨어**(on-demand software, 온디맨드 소프트웨어)라고도 한다.
  - 모든 서비스가 SaaS화 되고 있음.
    - Ex: Web browsers, client launcher
  - 개발자로 취업하기 위해 가장 중요한 것이 web service
- SaaSbook - Engineering Software as a Service (필수요소만)
  - David Patterson (저자: 컴퓨터 구조 및 설계)

### PaaS

### IaaS





## WWW(World Wide Web): 인터넷

* **http**(hypertext transfer protocol): hyptertext(html) 문서를 주고받는 protocol
* 모든 서비스는 **요청(request)과 응답(response)**
  * 인터넷 재화: 문서(데이터)
* (남의 컴퓨터 주소: 110.192.0.1 ip)/page/subpage/article.html
  * ip는 어려우니까 도메인 주소(nickname: google.com)로 대리저장함
* DNS(#**domain** name system): 전화번호부같은 역할
  * 어디로 가고싶으면: domain검색해서 돌려줌
    * DNS가 다운되면 검색해서 못들어가고 ip통해만 접근 가능함(상식)
    * 예: **.com**



### IP

* 172.217.27.78: 8bit(0~255)까지의 숫자로 구성된 숫자의 집합으로, 각자가 가지고 있는 주소와 동일하다.
* 이 key로 검색하면 찾을 수 있게끔 DNS에서 관리함



### URL(uniform resource locator)

* https://post.naver.com/viewer/postView.nhn?volumeNo=17584060



### Static web

* 어떤 요청이든 한가지 응답



### Dynamic Web

* Web Application program (Web Service 또는 Web APP)



### Framework

*  클래스와 라이브러리가 합쳐진 형태
  *  모듈화를 하는 이유 중 하나가 재사용성

* Flask, Django, Bootstrap



### Cloud

* 컴퓨터 사서 server 돌릴 필요가 없다
  * server :  요청을 응답해주는 곳

* AWS
  * Lambda - 함수를 짜면 함수 하나만 돌려주는 서비스

* 가상화기술의 발전



### Browser

* 인터넷에 대한 이해 없이 포장해서 요청, 응답해주는 곳
* Chrome: 
  * **Web Developer**(Extension):  JavaScript, Layout 등 웹개발에 필요한 것 알려줌



### 요청의 종류

* 줘라(Get)
* 받아라(Post)



### Web service

* 요청 패턴:
  * http(s)://hpsk/lecture/1
* html(request) <-> html(get)



### W3C(World Wide Web Consortium) : 웹표준

* html / CSS
  * Hypertext - 비선형적 텍스트(링크)
  * hyperlink - 텍스트 이동
  * markup(기호(tag)로 역할을 설정)
  * CSS - Style sheet: 스타일 정의
    * cascading(상속: 폭포처럼 위에 있는 요소들이 아래로 떨어진다) 통해 이뤄짐)
    * poiemaweb.com (CSS tips)
    * CSS 너무 빡침!!!
      * Framework (template 틀): **Bootstrap**
* http: hypertext를 왔다갔다할 수 있게 하는 프로토콜
* http(아무나) 
* https
  * 암호화해서 정보교환
  * 자체 암호화는 과부하 -> 인증서(대리업체) 받아서 암호화)
* IE: 표준 안지킴 - MS가 원하는 방향으로만 개발 - 노답
* Chrome: 표준 지킴 - 응용 개발 - good





### JavaScript

* 파이썬과 비슷
* ECMA스크립트 규격(ES6 표준) - JavaScript 업그레이드