#include <iostream> // C++의 표준 입출력에 필요한 것
// std::cout, std::endl // C의 stdio.h와 비슷
// C와 다르게 header파일에 .h가 붙지 않는다

// 이름공간 정의
namespace header1 {
    int foo() {
        foo();
    }
    void bar();
}

using header1::foo; // header1이란 이름 곤간에 들어있는 foo 만 쓸거다

using namespace std; // 이름공간 안에 정의된 모든 것들을 ::없이 사용
// 권장되지 않음; std에 이름이 겹치는 함수를 만들게 된다면 오류 발생
// 표준 라이브러리는 매우 거대하므로 잘못가능성


int main() { // 가장 먼저 실행되는 함수
    std::cout << "Hello, World!" << std::endl;
    // std는 이름 공간(namespace)
    // std는 표준 라이브러리의 모든 함수, 객체 등이 저장된 namespace
    // 어떤 정의된 갳에에 의해 어디 소속인지 지정해주는 것
    // 같은 이름이라도 소속된 이름 공간이 다르면 다른 것으로 취급
    // 그냥 cout이라고 하면 컴파일러가 cout을 찾지 못함

    cout << "Hello!" << endl; // using namespace std;


    header1::foo(); // header1 이름공간에서 foo() 호출

    foo(); // using 키워드를 통해 쉽게 쓸 수 있음

    return 0;
}

// cout은 `ostream` 클래스 객체로 표준 출력(stdout에 대응) 담당
// std::cout << 출력할 것 << 출력할 것 << 출력할 것;
// << ... << std::endl // 화면에 출력해주는 함수

// std::cout << std::endl; 화면에 엔터 하나를 출력하는 것



// 정의된 namespace안의 내용은 해당 파일 안에서만 접근
// 헤더 파일을 통해 위 파일을 받았다 하더라도 사용 불가능
namespace {
    // 이 함수는 이 파일 안에서만 사용 가능
    // 이는 마치 static init OnlyInThisFile() 과 동일
    int OnlyInThisFile() {}
    // static int x와 동일
    int only_in_this_file = 0;
}

int yo() {
    OnlyInThisFile();
    only_in_this_file = 3;
}


int io() {
    int i;

    std::cin >> i;
    // cin(stdin)은 >>를 통해 input
    std::cout << "yo" << i << std::endl;
    // cout(stdout)은 <<를 이용해 출력

    // scanf에선 &를 붙였는데 C++에선 필요 없다
    // type값도 필요 없다, cin이 알아서 처리해줌
}