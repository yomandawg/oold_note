# Data Structures

> 자료구조



### Array and Linked List

> 선형 자료구조

#### Array

* 가장 기본적인 자료구조
* 논리적 저장 순서 == 물리적 저장 순서
* `index`로 해당 원소에 접근 == O(1) search
  * *random access* 가능
* 삭제&삽입: 원소 접근(O(1)) &rarr; 작업(O(n))
  * 어느 원소를 삭제하거나 삽입하면 연속적인 특징이 깨지고(빈 공간) `shift` 추가 cost 발생
  * O(n) worst case

### Linked List

* Array의 일부 문제점 해결
* 각각의 원소는 다음 원소 기억(pointing)
  * 이 부분만 바꿔주면 되므로 삭제 삽입 O(1)
* 원하는 위치를 search 과정에서 처음부터 다 확인해야함
  * 논리적 저장 순서 != 물리적 저장 순서
* 삭제&삽입: 원소 접근(O(n)) &rarr; 작업
  * 결국 search도 O(n), 삽입&삭제도 O(n)으로 같다
* despite its cons, Tree 구조의 근간

#### 실습

* Array를 기반으로 한 Linked List
* ArrayList를 기반으로 한 Linked List



### Stack and Queue

> 선형 자료구조

#### Stack

* 선형 자료구조의 일종
* Last In First Out (LIFO) - 나중에 들어간 원소가 먼저 나와
* 호출 시 가장 위에 있는 것

#### Queue

* First In First Out (FIFO)
  * Garbage Collection(Priority Queue)
  * Java collection의 queue는 인터페이스

#### 실습

* Queue 이용한 heap 자료구조
* Stack 두개로 Queue 자료구조







---

MCU(ST) STM32F4 

- ARM 아키텍쳐 - CORTEX M
- DSP and FCU



ARM(크게 종류가 3가지)

* CORTEX A - 핸드폰에 들어가는 대부분 칩(high performance)
* CORTEX R - RTOS(real time) Automotive 또는 IoT 기기들, 주문기계들(중급성능)
* CORTEX M - 학습용 Arduino 저전력(IoT)

* ARM9
* ARM7

---

Automotive 전장사업 레이어 수직계열

티어1 - 완성차

티어2 - 현대모비스, 오트론(infortainment 시스템)

티어3 - 삼성전자같이 부품 칩 제공

* RTOS(Real time OS), 신뢰성(폰과는 다르게 버그가 없어야함)

---

ASIC - 특화된 명령어만 계속 수행

* 딥러닝, 이미지프로세싱, NPU
* 반복적으로 똑같은 프로세싱을 하는 것
* 이미테이션에서 만든 컴퓨터가 첫번째 - 특화된 명령어
* 소프트웨어보다 빠르다
* NPU - 인공지능 특화칩: 논리회로부터 알고리즘
* 명령어의 체계가 특화돼있어



일반 CPU - 대부분 레지스터 접근할 수 있는 명령어의 집합

* ASIC과 반대로 여러가지 조합으로 명령어 만든다
  * generl purpsose

* RISC(reduced instruction set computer) 
  * 대부분의 ARM(모바일) 칩들
  * 저전력 칩
  * 쪼그만 칩들
  * 명령어가 단순하기 떄문에 간결하게 프로그램 짤 수 있다

* CISC(complex instruction set computer) - 인텔 옛날까지
  * x86 CISC
  * 좀 더 복잡한 명령어 - 빠름

---

IoT





---

AWS

* 1년 무료 - T2micro 서버



---

DAU

MAU

트래픽 - google analytics (ga)

* 간편하게 앱에  javascript 붙이기만 하면 구글이 request header을 분석해준다

유저수



---

Hashing

- username+password+salt string concatation (통합 정보)

- 남겨진 cookie를 확인해서 유저가 로긴상태인지 아닌지 `session 공간`에서 확인
- session엔 유저의 통합정보가 관리됨
- 유저가 request할 때 cookie와, 정보를 보내면 -> 그 값을 session에서 찾는다
- 만약 비번 바꾸면 username+password+salt 에서 password가 바껴서 hash값이 바뀐다
  - hash값이 reload돼야해!
  - 이 값을 억지로 바꿔줘야해 `update_session_auth_hash`
    - 세션에 있는 auth hash를 바꿔줘

---

HTTP: 통신 규약

- cookie가 필요한 이유: 서로 누군지 밝히기 위해
- (과거에 설계됐을 때, 서버 작으니까)서버쪽에서 최소한의 정보를 쥐고있고, client쪽에서 많은 정보(쿠키)를 가지고 있어
  - request 보낼 때, cookie를 갖고 있는 사람은 다 그전 유저라고 생각함
- html header이 작은 이유
- 시크릿모드 -> 서버에서 아무 cookie도 받지 않음
- 쿠키를 복사하면 그사람인척 할 수 있다
- 취약한 사이트는 쿠키만 조작하면 로그인한척 할 수 있음