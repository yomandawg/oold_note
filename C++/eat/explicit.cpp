#include <iostream>

class MyString {
    char* string_content; // 문자열 데이터를 가리키는 포인터
    int string_length; // 문자열 길이
    int memory_capacity; // 할당 메모리

    public:
        // MyString(int capacity); // capacity 만큼 미리 할당함.
        explicit MyString(int capacity); // explicit에 주목

        MyString(const char* str); // 문자열로부터 생성
        MyString(const MyString& str); // 복사 생성자
        ~MyString();
        int length() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}
MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {}

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void DoSomethingWithString(MyString s) {
    // Do Something
}

int main() { 
    // MyString s(3);
    DoSomethingWithString(3); // ???? 컴파일 오류!
    // int capacity 를 인자로 받는 생성자가 explicit으로 되어있기 때문
    // explicit은 명시적 이라는 뜻으로 MyString 생성자를 explicit으로
    // 선언한다면 이 생성자를 이용한 암시적 변환을 수행하지 못하게 막을 수 있다.
    // 실제 컴파일 오류 메세지를 보아도, int 에서 MyString으로 변환할 수 없다고 나온다.ㄴ

    // explicit은 또한 생성자가 복사 생성자의 형태로도 호출되는 것을 막게 함.
    // 예를 들면,
    MyString s = "abc"; // MyString s("abc");
    MyString s = 5; // MyString s(5);
    // MyString(int capacity); 에 explicit이 없을 경우, 위 코드는 잘
    // 작동한다, 왜냐면 컴파일러가 알아서 적당한 생성자를 골라서 호출하기 때문
    // 그렇지만 생각해보면, MyString = 5; 는 마치 s에 5를 대입하고 있다는
    // 의미를 전달하게 된다. 실제로는 capacity를 5로 해주는 것인데도..
    // 따라서, explicit으로 MyString(int capacity)를 설정하면
    MyString a(5); // 허용
    MyString s = 5; // 컴파일 오류
    // 위와 같이 명시적으로 생성자를 부를 때만 허용할 수 있다.
}


/*
void DoSomethingWithString(MyString s) {
    // Do something...
}

DoSomethingWithString(MyString("abc"));
당연히 된다. MyString 객체를 생성해서 이를 인자로 전달.

DoSomethingWithString("abc");
일단 인자로 MyString을 받고 있는 함수에 "abc"(MyString 타입이 아닌)을
넣더라도 C++ 컴파일러는 똑똑해서 "abc"를 어떻게 하면 MyString으로 바꿀 수
있는지 생각한다.
MyString의 생성자 중, MyString(const char* str); 문자열로부터 생성
이 있기 때문에 알아서 MyString("abc")로 인자를 변환시켜서 컴파일한다.
이와 같은 변환을 암시적 변환(implicit conversion)이라고 부른다.

하지만 암시적 변환이 언제나 편리한 것은 아니다. 예상치 못한 암시적 변환이
일어날 경우는 문제!

DoSomethingWithString(3); 을 할 경우 높을 확률로 잘못된 인자를 전달했지만
컴파일러는 이를 오류로 판단하지 않는다.
위의 MyString 생성자에서 int capacity를 인자로 받는 생성자가 있기 때문에
위의 경우 DoSomethingWithString(MyString(3));으로 암시적 변환을 거친다.

이는 문제!
그러므로 C++에서는 원하지 않는 암시적 변환을 할 수 없도록 컴파일러에게 명시할 수
있다. 바로 explicit 키워드로!
 */