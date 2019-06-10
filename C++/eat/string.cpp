// C++에서는 웬만하면 char 배열보다 string을 사용해서 문자열을 다룬다
// C언어에서는 종료 문자열(Null-tested)라는 개념을 도입해 문자열 끝에 NULL을 붙인다
// 하지만 이는 문자열의 크기를 바꾸던지, 다른 문자열을 붙인다던지 하는 작업들을 귀찮게 만든다
// 그래서 문자열 클래스를 따로 만들어서 클래스 차원에서 지원해주면 편하겠다!
// C++에선 표준 라이브러리로 string 클래스 지원함 (<string> 헤더파일)

// 우리가 만들 MyString 클래스의 멤버 변수로 무엇이 필요할까?
// 1. 문자열 데이터가 저장된 공간을 가리키는 포인터
// 2. 문자열 데이터의 길이
// 객체에 문자열 데이터를 직접 보관하는 것이 아니라, 저장된 공간을 가리키는 포인터를 보관하는데
// 이는 나중에 문자열 데이터의 크기가 바뀔 대, 저장된 공간을 가리키는 방식으로 하면 그 메모리를 해제한 뒤에
// 다시 할당하면 직접 보관할 때 생기는 문제를 해결할 수 있음!
// 또한 문자열 데이터의 길이를 보관하는 이유는 계속 길이를 구하는 것이 상당히 불편하므로

#include <iostream>

class MyString {
    // private 정보들 - 중요한 정보
    char* string_content; // 문자열 데이터를 가리키는 포인터
    int string_length; // 문자열 길이
    // 이 변수들을 만지지 않고도 제어할 수 있는 함수를 제공해야 한다.

    public:
        // 생성자
        MyString(char c); // 문자 하나로 생성
        MyString(const char* str); // 문자열로부터 생성
        MyString(const MyString& str); // 복사 생성자(default 형식)
        // 어떤 방식으로 문자열을 저장할 것인지 생각해보면 -
        // string_content에 C형식의 문자열(NULL 포함)을 보관하는 것 => 문자열 끝 체크 string_length로 해결
        // => 필요없는 정보를 빼고 실제 문자만 보관하는 것

        ~MyString(); // 동적할당 하므로 소멸자 처리 필수

        int length() const;
        void print() const;
        void println() const;
};

MyString::MyString(char c) {
    string_content = new char[1]; // 동적 할당 처리 => 소멸자에서 처리해줘야 함
    string_content[0] = c;
    string_length = 1;
}
MyString::MyString(const char* str) {
    for (string_length = 0; str[string_length]; string_length++)
    // string_length = strlen(str);
    string_content = new char[string_length]; // 동적 할당 처리 => 소멸자에서 처리해줘야 함

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; } // 소멸자에서 동적해제
// C언어는 구조체같은 걸로 문자열을 구현했다면 이를 일일히 해제하는 것을 처리해야하기 때문에 매우 힘듦
// 클래스는 안에서 어떻게 돌아가는지 신경 안쓰고 구현 가능

// length의 경우 string_length의 값을 읽기만 하므로 상수 함수로 정의
int MyString::length() const { return string_length; }

// 문자열 출력 함수 - 읽기만 하므로 상수 함수
void MyString::print() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) std::cout << string_content[i];
    std::cout << std::endl; // 개행문자 자동 출력
}


int main() {
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();
}