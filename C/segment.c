#include <stdio.h>

int global = 0; // 전역 변수 (global)
int global2; // 정의와 동시에 자동으로 0으로 초기화 된다.

int function() {
    global++;
    return 0;
}

int main() {
    global = 10;
    function();
    return 0;
}

// 지역 변수의 경우 함수가 종료될 때 파괴되는데,
// local variable(지역변수)는 메모리 상의 '스택'에 저장된다
// 배열 또한 지역 변수(의 모음) 이라고 보면 된다

// 전역 변수의 경우 프로그램이 시작할 때 만들어졌다가
// 프로그램이 종료될 때 파괴된다.
// 전역 변수는 지역 변수와 는 달리 메모리의 데이터 영역(Data Segment)에 할당
// 모든 전역 변수는 정의 시 자동으로 0으로 초기화 된다.

// 10개의 함수에 대해 각각 호출 회수를 세기 위해 10개의 전역 변수가 필요하다?
// => 심각한 문제: 전역 변수는 모든 함수에서 접근할 수 있기 떄문에
// 조심스럽게 사용해야 하는 전역 변수를 수십개 선언하면 필연적 문제 발생
// 최소한의 전역 변수 사용을 권고

// 함수가 종료되어도 값이 변경되지 않는 지역변수는 없을까?
// 정적 변수(static variable)

int func() {
    static int how = 0;
    how++;
    return 0;
}

int func2() {
    static int how; // 위와 이름은 같지만 메모리 상에 다른 곳에 존재
    // 0으로 자동 초기화
    how++;
    return 0; // 함수가 종료되어도 static은 how 값을 유지한다.
}
// 정적 변수의 경우 전역변수처럼 'data segment' 데이터 영역에 저장됨
// 특별한 값을 정해주지 않는 한 0으로 자동 초기화



/* 데이터 세그먼트 구조
C언어는 자체적으로 스택/힙을 따로 구분하지 않다
하지만 대부분의 운영체제에서 프로그램을 실행한다면, 힙과 스택 영역을 구분해서 만든다

프로그램이 실행될 때, 프로그램은 RAM에 적재된다.
모든 내용이 RAM 위로 올라오게 되는 것 - 모든 내용이라 하면
프로그램의 코드와 데이터를 의미하는 것
이렇게 RAM 위에 올라오는 프로그램 내용을 크게 나누어
코드 세그먼트(Code Segment)와 데이터 세그먼트(Data Segement)로 분류함

데이터 세그먼트란

메모리 주소 점점 낮아짐

스택 - 지역변수가 위치
--
--
힙
데이터 영역 - 전역 변수와 정적 변수가 위치
Read-Only Data - 상수와 리터럴
코드 영역

와 같이 메모리에 배치된 것을 알 수 있다
읽기전용(read only) data는 상수와 리터럴 등의 값이 절대로 변경될 수 없는 부분

스택은 지역변수가 늘어나면 크기가 아래로 증가하다가 지역변수가 파괴되면 다시 스택의
크기는 위로 줄어들게 됨.
즉 스택이 늘어나는 방향은 메모리 주소가 낮아지는 방향.

*/

/* 메모리 배치의 모습

#include <stdio.h>
int global = 3; // 1177010
int main() {
    int i; // 1af8c8
    char *str = "Hello"; // 1175a28
    char arr[20] = "What!"; // 1af8a0
}

프로그램 실행시 RAM이 어디 위치하게 될지는 모르는 것이기 따문에 항상 주소 다름

read only인 str의 경우(Literal)  출력 주소중 가장 작음
RO data는 데이터 세그먼트 맨 아래에 위치한다.

glbobal 주소값을 보면 str(literal) 보다는 살짝 크지만 여전히 낮음
데이터 영역에 위치한다.

i를 보면 지역변수이기 때문에 stack에 존재하는데, i보다 나중에 추가된
arr의 주소값이 더 낮다
이것은 stack이 메모리 주소 아래로 쌓이기 때문

--STACK--
        int i
        arr[19]
        ...
        arr[0]
--STACK--
--HEAP--
--HEAP--
--DATA--
        global = 3
        "Hello"
--DATA--
--CODE--
        ...
--CODE--

*/