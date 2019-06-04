#include <iostream>

int change_val(int *p) {
    *p = 3;
    return 0;
}

// C++ reference
int change_val_ref(int &p) { // 인자로 int &p == reference(참조자)
    // 인자를 number로 호출 시, p가 number의 별명이 되는 셈
    p = 3; // number = 3;을 하는 것과 동일(포인터 없이)
    return 0;
}

int main() {
    int number = 5;
    int ref_number = 5;

    std::cout << number << std::endl; // 5
    std::cout << ref_number << std::endl; // 5
    change_val(&number);
    change_val_ref(ref_number);
    std::cout << number << std::endl; // 3
    std::cout << ref_number << std::endl; // 3
}


int refernece() {
    int number;
    int &ref = number; // reference(참조자) 정의
    // 참조자는 무엇인가를 "참조"해야하기 때문에 선언시 초기화해야함
    // 포인터와 달리 메모리 값을 보관하지 않음
    // 컴파일시 원래 가리키던 변수의 주소값으로 다 치환됨
    // (함수에 인자로 넘겨줄 때 레퍼런스가 메모리 상에 존재하기는 하지만
    // 포인터처럼 어떤 존재하는 실체가 아니고 단순히 '별명' 임)
    
    // 한 번 초기화 되면 다른 변수의 별명이 될 수 없다
    int a = 10;
    int &ref = a;
    int b = 3;
    ref = b; // ref가 가리키는 a가 b로 바뀐다(a = 3)
    // &ref = b;는 a의 주소값을 3으로 변경한다 라는 의미로 말이 안됨
    // ref &= b;는 ref = ref &b ==> a = a & b;로 다른 뜻
    // 레퍼런스는 포인터로 치면 int const *와 비슷하다(메모리공간은 안차지하지만)
    // 한 번 별명이 된다면 영원히 바뀔 수 없다


    int& ref = number;
    int* p = &number;

    ref++; // number의 값을 1 증가시킴 == number++;
    p++; // 포인터 p의 주소값이 4만큼 증가돼서(int가 4byte) 다른 것을 가리킴
    // 참조자를 사용하면 귀찮은 포인터 관련 연산을 생략 가능
    // 원래 변수라고 생각하면 되는 일
}


int ex() {
    int x;
    int& y = x; // x의 다른 이름 y
    int& z = y; // y의 다른 이름 z
    // => x의 다른 이름 y의 다른 이름 z
    // 결국 x=y=z
    // C와는 다르게(int**) int& 하나만 있음

    x = 1;
    std::cout << x << y << z << std::endl; // 1 1 1
    y = 2;
    std::cout << x << y << z << std::endl; // 2 2 2
    y = 3;
    std::cout << x << y << z << std::endl; // 3 3 3

    std::cin >> x;
    // 포인터로 전달 안하고 reference로 전달하므로 &를 붙일 필요가 없는 것
}