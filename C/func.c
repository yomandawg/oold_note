#include <stdio.h>

int print_hello() { // 함수의 정의 definition
    printf("Hello! \n"); // body
    return 0; // 함수 종료 및 반환
}

int ret() {return 1000;} // int형 함수는 int형을 반환함

int main() { // 프로그램을 실행하면 컴퓨터가 main함수부터 찾는다
    print_hello(); // 함수 호출(call) - ()는 컴파이얼에게 함수이다 라는 것을 알린다

    int a = ret(); // 함수 반환값으로 선언 가능
    printf("%d \n", a);

    return 0; // main함수 return은 운영체제가 받는다
    // Windows 또는 Linux 등등
    // 정상 종료: 0, 비정상 종료: 1 규정
    // 이 정보를 활용하는 경우는 매우 드물다.
}

int magicbox() {
    // i += 4; // 오류다! magicbox를 호출하면 i 변수에 대한 정보를 갖고있지 않다
    return 0;
}

// 매개변수
int slave(int master_money) { // 인자 or 매개변수(arguement or parameter)
    // 소괄호 안에 int 변수 정의: 호출하는 코드로부터 어떤 값을
    // master_moeny라는 int형 변수에 인자(매개변수라고도 부름)로 받아들이겠다
    master_money += 10000;
    slave(500); // slave를 호출할 때, slave에 500이라는 값을 전달하겠다
    // 함수를 호출하는 함수: caller
    return master_money;
}

// 다른 함수의 변수의 값을 수정하고자 하는 함수를 만드려면?
// => 각 함수의 세계는 서로에 무슨 변수가 있는지 모른다
// => 포인터를 이용하면 된다!