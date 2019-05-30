# Selenium

* 웹앱 테스트하는 프레임워크
* `webdriver`이라는 API를 통해 운영체제에 설치된 브라우저를 제어
    - 브라우저를 직접 동작시킨다는 것은 JavaScript를 이용해 비동기적인 컨텐츠들을 가져올 수 있다는 것
    - 눈에 보이는 컨텐츠면 모두 가져올 수 있다!
    - requests에서 사용했던 `.text`의 경우 브라우저에서 소스보기를 한 것과 같이 동작하여, JS등을 통해 동적으로 DOM이 변화한 이후 HTML을 보여주지 않는다.
    - 반면 Selenium은 실제 웹 브라우저가 동작하기 때문에 JS로 렌더링이 완료된 후의 DOM 결과물에 접근이 가능하다.

> `pip install selenium` - 자주 업데이트 하자
> `pip install bs4`

* `webdriver`을 통해 디바이스에 설치된 브라우저들을 제어할 수 있다.
    - Chrome Driver
        - version 체크 필수
        - 경로를 나중에 Selenium 객체 생성할 때 지정해야 함

* `PhantomJS` webdriver
    - WebTesting을 위해 나온 Headless Browser(화면이 존재하지 않는다)
    - JS등의 처리 가능 및 CLI 환경에서 사용 가능
    - CLI 서버 환경에서 돌아가는 크롤러에선 PhantomJS를 사용 용이
    - 개발 종료 (크롬의 headless 모드 사용 가능)


## 사이트 브라우징
> `from selenium import webdriver`

* Chrome
    - chromedriver의 위치 지정
    - `driver = webdriver.Chrome('.chromedriver')`

* Selenium은 기본적으로 웹 자원들이 모두 로드될 때까지 기다려주지만, 암묵적으로 모든 자원이 로드될 때까지 기다리게 하는 시간을 지정 가능
    - `driver.implicity_wait(3)`

* URL 접근 api
    - `driver.get('https://google.com')`

* 페이지 단일 element 접근 api
    - `find_element_by_name('HTML_name')`
    - `find_element_by_id('HTML_id')`
    - `find_element_by_xpath('/html/body/some/xpath')`

* 여러 elements 접근
    - `find_element_by_css_selector(‘#css > div.selector’)`
    - `find_element_by_class_name(‘some_class_name’)`
    - `find_element_by_tag_name(‘h1’)`

> 위 메소드들 활용시 HTML을 브라우저에서 파싱해주기 때문에 BS를 사용하지 않아도 된다.
> 하지만 Selenium에 내장된 함수만 사용가능하기 때문에 좀 더 편리한 soup객체를 이용하려면 `driver.page_source` API를 이용해 현제 렌더링된 페이지의 Elements를 모두 가져올 수 있다.


## 네이버 로그인하기
> 네이버는 requests를 이용해 로그인이 어렵다.
> 프론트 단에서 JS처리를 통해 로그인 처리를 하기 때문인데, Selenium을 이용하면 아주 쉽게 로그인을 할 수 있다.

* `driver.get('https://nid.naver.com/nidlogin.login')`

* 네이버 로그인 화면을 보면 아이디를 입력받는 부분의 name이 `id` 비번이 `pw`이다.
    - `find_element_by_name`으로 input 태그를 잡고, 값을 입력하자

* 로그인 버튼 누르기
    - `driver.find_element_by_xpath('//*[@id="frmNIDLogin"]/fieldset/input').click()`
    