# OS

>  운영체제

---

## 1. 개요

* 사용자가 컴퓨터를 쉽게 다룰 수 있게 해주는 인터페이스
  * 컴퓨터 자원을 효율적으로 관리하기 위한 시스템
  * 공통된 소프트웨어 플랫폼
  * 컴퓨터 응용 프로그램 관리자
* HW와 SW를 관리하는 소프트웨어의 전체
* 커널이 포함된 패키지 = OS

---

## 2. 구성 요소

![파일:UNIX_structure.png](https://w.namu.la/s/714c0e6deee4500d49151cfdb943fe1590236291f619ca7cc91e15b159db517b71a2c4f9e9338b74bddec3ec95c809820e8ba7813b8e0eff59a4267058c002f54b84b1b781e249c16d5204699bc21341367549103ef079c0642b46e2fa93fd11) Unix 구조

* 하드웨어 &rarr; 커널 &rarr; 셸(&rarr;)어플리케이션
* 커널이 드라이버 이용해 하드웨어 제어, 서로 다른 프로그램들이 갖가지 하드웨어 호환성을 위해 API 제공
  * 동일한 환경을 제공해서 하드웨어나 환경이 달라지더라도 프로그램을 사용할 수 있도록 플랫폼 제공
* 

---

#### Shell

* OS와 커널 사이에서 이용자의 명력을 해석하고 처리 결과를 뿌려주는 시스템 프로그램
* 이를 통해 어플리케이션을 실행
* **CLI**(command-line interface 또는 CUI(character-user interface))
  * DOS, cmd, bash(unix)
  * 불친절 - 기본 명령어 외워야
  * 자원 적게 소모, 안정적, 빠름
    * 서버 관리, 서버 프로그램 등 작업 자동화 효율
    * shell script(unix 자동화)
    * batch(window 자동화)
  * **SSH**(Secure SHell) - 원격 컴퓨터 access 위한 unix 기반 *명령 interface* 및 프로토콜
    * 네트웍 관리자들이 서버 원격 제어 위해 사용
* **GUI**(graphical user interface)

---

#### 인터페이스

* 서로 다른 두 개의 시스템, 장치 사이에서 정보나 신호를 주고받는 접점
* 사용자가 기기를 쉽게 동작시키는데 도움을 주는 시스템

---

#### 펌웨어

* 전자기기의 기본적인 제어 및 구동을 맡는 OS의 일종
* 기본 OS, 기능 추가 할 수 없다
* ROM에 기록된다
* 부품으로 취급하기도 함
* 탑재된 기기의 OS를 담고 있기 때문에 잘못되면 벽돌
  * CPU의 디버그 모드로 펌웨어를 밀어 넣으면 복원 가능
* 대부분 리눅스 커널 기반

---

### 커널

* OS를 규정하는 매우 중요한 부분
* 하드웨어 자원을 필요한 프로세서에 나눠주고, 덩달아 프로세스 제어(task manager), 메모리 제어, 프로그램이 운영체제에 요구하는 시스템 콜 등을 수행하는 부분으로 OS 맨 하부에서 돌아감
* 드라이버를 이용해서 CPU나 그래픽카드 등의 하드웨어 제어
* 여러 응용프로그램이 갖가지 다른 하드웨어에서 돌아가도록(호환성) API 제공
  * 예) 웹브라우저가 화면에 점을 찍는다: 커널에서 제공하는 점 찍는 함수 호출 -> 커널이 드라이버 참조해 그래픽카드에 점 찍으라 명령
* 흔히 쓰는 OS는 커널 위에 여러가지 layer을 올린 것

  * 커널이 날아가면 무용지물

* **mutex**
* **semaphore**

* **단일형 커널(monolithic kernel)**

  ![파일:external/www.makelinux.net/Linux_kernel_diagram.png](https://w.namu.la/s/d1b16e63d4d2e00860295607b56f056e4d9e128f50e53682131913c186e38c808a77d57bfe681a1de53b98bfe099dfae3e72ef4cf78d15d6a767324f25aef48b76ab1f23c632b28bcd7d049abd8e5c788bf2edb758c486b629dba564b3e90a03)

  * Unix 계통
    * Linux 커널 == 안드로이드 커널
  * 입출력, 네트워크, 디바이스 지원 등의 OS에서 일어나는 모든 일을 한 개의 커널이 다 처리하는 방식
  * 속도가 빠르고, 디자인 편리
  * 커널의 크기가 너무 커질 수 있어서 잠재적 안정적 문제


* **마이크로커널(microkernel)**

  ![파일:external/www.linuxpromagazine.com/Figure-1.png](https://w.namu.la/s/63edd9de4077241a28b6948bb404dbd5156a8c92dac03213137f0a204699010d81edbeca1eb57eb3f8f138116d3b2c89d36fd26a043413a82255d0ee10e43f460453d1c8a8925804b8589af7ea202ed8b73d463177ae8acae0e55ad8ed52871b)

  * 시스템 콜 등의 서비스, 디바이스 관리 제외
    * 안정석 높이고 커널 크기 &darr; = 보안 굿
      * 퍼포먼스 저하


* 혼합형 커널(hybrid kernerl)**

  ![파일:external/upload.wikimedia.org/500px-Windows_2000_architecture.svg.png](https://w.namu.la/s/58785989400544c81d6ce1ddaa96e7f4290e4beba6c86b3439ce75ff8da71087fd220a44e0be008883454343b784b9067c2736c68dfe773c7ce6a90e262b986623b8d369178d90f56537a2f6a83e931d176721cddca5a811c7b8836375dcb88e)

  * 윈도우 NT 계열
  * 단일형 커널에 마이크로커널 디자인을 넣어 만든 방식

---

#### 드라이버

* 디바이스 드라이버 - 주변기기의 입출력을 통제하는 소프트웨어
* OS 거쳐서 설치
* 펌웨어 다음으로 하드웨어와 가장 직접적으로 관련된 소프트웨어



