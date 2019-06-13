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
#include <string.h>

class MyString {
    // private 정보들 - 중요한 정보
    char* string_content; // 문자열 데이터를 가리키는 포인터
    int string_length; // 문자열 길이
    // 이 변수들을 만지지 않고도 제어할 수 있는 함수를 제공해야 한다.

    int memory_capacity;

    public:
        // 생성자
        MyString(char c); // 문자 하나로 생성
        MyString(const char* str); // 문자열로부터 생성
        MyString(const MyString& str); // 복사 생성자(default 형식)
        // 어떤 방식으로 문자열을 저장할 것인지 생각해보면 -
        // string_content에 C형식의 문자열(NULL 포함)을 보관하는 것 => 문자열 끝 체크 string_length로 해결
        // => 필요없는 정보를 빼고 실제 문자만 보관하는 것

        ~MyString(); // 동적할당 하므로 소멸자 처리 필수


        // str.assgin("abc");
        // str에는 원래 있었던 문자열이 지워지고 abc가 들어가게 됨
        MyString& assign(const MyString& str);
        MyString& assign(const char* str);

        MyString& MyString::insert(int loc, const MyString& str);
        MyString& MyString::insert(int loc, const char* str);
        MyString& MyString::insert(int loc, char c);

        MyString& erase(int loc, int num);

        int length() const;
        void print() const;
        void println() const;


        int find(int find_from, MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
        // 앞서 insert 함수를 구현한 방법처럼, 맨 위의 MyString을
        // 인자로 받는 find만 제대로 구현한 후에 아래 두개의 find는
        // 맨 위읭 함수를 이용해서 구현하는 방식으로 처리.
        // 참고로 find함수는 find_from에서부터 시작해서 가장 첫번째
        // str의 위치를 리턴하게 됩니다. 그리고 str이 문자열에 포함되어
        // 있지 않다면, -1을 리턴하게 된다. 이러한 바업으로, 어떤 문자열
        // 내에 있는 모든 str들을 찾을 수 있는 for문을 생각할 수도 있다.

        int compare(const MyString& str) const;


        int capacity();
        void reserve(int size);


        char at(int i) const;
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


// assign 함수
MyString& MyString::assign(const MyString& str) {
    if (str.string_length > string_length) {
        // 그러면 다시 할당을 해줘야 한다.
        delete[] string_content;

        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    // 굳이 str.string_length + 1 ~ string_length 부분은 초기화
    // 시킬 필요는 없다. 왜냐하면 거기까지는 읽어들이지 않기 때문이다.

    string_length = str.string_length;

    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > string_length) {
        // 그러면 다시 할당을 해줘야 한다.
        delete[] string_content;

        string_content = new char[string_length];
        memory_capacity = str_length;
    }
    for (int i = 0 ; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}
// string의 크기가 작으면 동적 할당을 수행하는데 큰 시간이 필요하지
// 않겠지만, 우리의 MyString 클래스는 어떤 크기의 문자열에 대해서도
// 좋은 성능을 보여주어야만 하기 때문에 위처럼 인자로 입력받는 문자열의
// 크기보다 작다면 굳이 동적 할당을 할 필요가 없게 되죠.

// 따라서 그 경우에는 그냥 그대로 복사하게 됩니다.
// 하지만 인자로 입력받는 문자열의 크기가 더 크다면, 현재까지는 이전에
// 동적으로 할당된 메모리 바로 뒤에 메모리를 추가하는 방법은 없으므로,
// 새로 동적할당을 해줘야만 합니다.

// 하지만 이 방식엔 문자가 있다.
/*
MyString str1("very very very long string");
str1.assign("short string");
str1.assign("very long string");
 */
// 맨 처음에 str1에 아주 긴 문자열을 할당하였습니다.
// 예를 들어서 그 문자열의 길이가 1000 바이트라고 생각해보면
// (물론 위 소스에서는 겨우 몇 바이트이겠지만 아무튼 아주 긴
// 문자열이라 생각하자)
// 그런 다음 str1에 다시 짧은 문자열을 assign 하였다고 가정하자.
// 우리 assign 함수에 따르면 맨 처음에 아주 긴 문자열의 길이가
// 짧은 문자열보다 훨씬 작을 것이므로 assign시에 특별히 동적 할당을
// 할 필요 없이 그냥 string_length 만을 줄인채 짧은 문자열로 덮어
// 씌우면 된다.

// 문제는 다시 str1에 긴 문자열을 assign시 발생(이번 긴 문자열은 이
// 전의 아주 긴 문자열보다는 약간 짧다고 가정).
// 비록 str1 에 이미 1000바이트에 달하는 공간이 할당되어 있는데도
// 불구하고 현재 짧은 문자열이 있기 때문에 새롭게 긴 문자열을 assign
// 시에 이미 1000바이트가 할당되어 있다는 사실을 알 수 없게 돼

// 따라서 assign함수는 문자열에 짧은 문자열을 위한 작은 크기에 공간만이
// 할당되어 있다고 생각하여 메모리을 해제하고 다시 많은 양의 메모리를
// 할당하는 매우 비효율적인 작업을 하게 됩니다.
// 이를 이미 할당되었는지 알고 있었다면 낭비할 필요가 없다.

// 따라서 이러한 비효율을 막기 위해 얼마나 많은 공간이 할당되어 있는지
// 알 수 있는 정보를 따로 보관하는 것이 좋을 것이라 생각된다.
// 이를 위해 memory_capacity라는, 현재 할당된 메모리 공간의 크기를
// 나타내는 새로운 변수를 추가한다.

// 이렇게 하면 앞선 상황과 같은 문제를 방지할 수 있다.
// 이렇게 capacity를 도입함으로써 여러가지 새로운 함수를 추가할 수 있다.
// 예를 들어 할당할 문자열의 크기를 미리 예약하는 reserve함수와
// 현재 문자열의 할당된 메모리 크기를 나타내는 capacity함수


int MyString::capacity() { return memory_capacity; }

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];

        delete[] prev_string_content;
    }
    // 만일 예약하려는 size가 현재 capacity보다 작다면
    // 아무것도 안해도 된다.
}
// reserve 함수의 경우, 할당하려는 크기가 현재의 할당된 크기보다 작다면
// 굳이 할당할 필요가 없게 됩니다. 따라서 size가 memory_capacity보다
// 클 경우에만 할당하도록 처리.


char MyString::at(int i) const {
    if (i >= string_length || i < 0) return NULL;
    else return string_content[i];
}
// 임의의 위치의 문자를 리턴하는 함수, 이전 C언어에서[]로 구현되었던
// 것, C문자열의 경우 구조상 배열의 범위를 벗어나는 위치에 대한 문자를
// 요구하여도 이를 처리할 수밖에 없었는데 (이는 결국 심각한 오류로 이어짐)
// C++의 경우 특정 위치의 문자를 얻는 것을 함수로 만들어서 올바르지 않는
// 위치에 대한 문제를 처리할 수 있다.
// i가 허용되는 범위를 초과한다면 NULL

// 문자 c혹은 C형식 문자열 str에서 생성할 수 있는 생성자와 복사 생성자
// 문자열의 길이를 리턴하는 함수(length)
// 문자열 대입함수(assign)
// 문자열 메모리 할당 함수(reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
// 특정 위치의 문자를 리턴하는 함수(at)



// insert 작업은 워낙 다양하게 사용되기 때문에 여러가지를 준비
// loc을 어떻게 사용할지 기준을 정해야하는데, 일반적으로 insert 함수에서
// 입력 위치를 받는 경우, 그 입력 위치 '앞'에 문자를 insert하는 경우가 많다.

// abc라는 문자열에 insert(1, "d")를 하면, 1의 위치에 있는 b앞에 삽입


MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어
    // abc라는 문자열에 insert(1, "d") 를 하게 되면 adbc가 됨
    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc < string_length) return *this;

    if (string_length + str.string_length > memory_capacity) {
        // 이제 새롭게 동적으로 할당을 해야한다.
        memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        // 일단 insert 되는 부분 직전까지의 내용을 복사한다.
        int i;
        for (i = 0; i < loc < i++) {
            string_content[i] = prev_string_content[i];
        }

        // 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
        for (; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete[] prev_string_content;

        string_length = string_length + str.string_length;
        return *this;
    }

    // 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게된다.
    // 효율적으로 insert하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.
    for (int i = string_length - 1; i >= loc; i--) {
        // 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
        string_content[i + str.string_length] = string_content[i];
    }
    // 그리고 insert 되는 문자 다시 집어넣기.
    for (int i = 0; i < str.string_length; i++)
        string_content[i + loc] = str.string_content[i];

    string_length = string_length + str.string_length;
    return *this;
}
// 위 함수만 제대로 만들어놓으면 나머지는 그냥 간단하게 처리 가능
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}
/*
훌륭한 MyString 클래스를 만들기 위해서, 한가지 더 생각해봐야
할 것은, insert는 많은 문자열을 한꺼번에 집어넣는 것이 아니라,
작은 크기의 문자열을 자주 집어넣는 경우가 많다.

즉 큰 크기의 문자열을 한 번에 넣는 작업보다는 작은 크기의 문자열들을
여러번 insert하는 명령을 많이 수행한다는 뜻이다.
그런데 많일 이미 capacity한계에 달한 문자열 클래스에 문자 a를 계속
추가하는 명령이라면?

while (some_condition) {
    str.insert(some_location, 'a');
}

마치 이와 같은 명령, 이미 str이 capacity 한계에 도달했다고 가정하므로,
매 insert마다 매모리를 해제하고, 1만틈 큰 메모리를 할당하는 작업을
반복하면 매우 낭비!

즉, 짜잘하게 계속 insert 하는 명령에서 메로리 할당과 해제를 반복하지 않도록
하기 위해, 통 크게 메모리를 미리 reserve 해놓는 것이 필요.
물론 무턱대고 엄청난 크기의 메모리를 할당하는것도 안됨.

만일 10바이트 밖에 사용하지 않는데, 이와 같이 짜잘하게 insert하는 문제를
피하기 위해 1000 바이트를 미리 할당해 놓는다면 소중한 자원의 낭비가 될 것

따라서 insert 작업에서의 잦은 할당/해제를 피하기 위해 미리 메모리를 할당해놓기와
메로리를 할당해 놓되 많은 자원을 낭비하지 않는다라는 구 조건을 모두 만족하는
방법이 있을까? 메모리를 미리 할당할 경우, 현재 메모리 크기의 두 배정도를
할당해놓는다는 것
 */

MyString& MyString::insert(int loc, const MyString& str) {
    // 이는 i의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
    // abc라는 문자열에 insert(1, "d") 를 하게 된다면 adbc가 된다
    
    // 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
    if (loc < 0 || loc > string_length) return *this;

    if (string_length + str.length > memory_capacity) {
        // 이제 새롭게 동적으로 할당을 해야한다.
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else
            memory_capacity = string_length + str.string_length;
    
    // 생략...    
    }
}

// 즉 새로 할당해야할 메모리 크기(string_length + str.string_length)가
// 현재의 memory_capacity 의 두 배에 달하는 크기를 할당해버리는 것
// 그리고 물론 insert 되는 문자열의 크기가 엄청 커서 memory_capacity의
// 두 배를 뛰어 넘어버린다면 그냥 예약을 생각하지 않고, 필요한 만큼
// 할당해버리면 됨. 이와 같은 방식으로 처리한다면, 빈번한 메모리의 할당/해제를
// 막을 수 있고, 또 많은 메모리 공간을 낭비하지 않을 수 있다.
// 참고로 이러한 방법은 C++에서 동적으로 할당되는 메모리를 처리하는데
// 매우 빈번하게 사용되는 기법중 하나입니다.




MyString& MyString::erase(int loc, int num) {
    // loc의 앞부터 시작해서 num 문자를 지운다.
    if (num < 0 || loc < 0 || loc > string_length) return *this;

    // 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고
    // 생각하면 됩니다.

    for (int i = loc + num; i < string_length; i++ ) {
        string_content[i - num] = string_content[i];
    }

    string_length -= num;
    return *this;
}
// erase함수는 위와 같이 생겼고, loc은 insert와 동일하게 loc의
// 해당하는 문자 앞을 의미합니다. 그리고 num은 지우는 문자 수를 의미하죠.
// 예를 들어서 abcd라는 문자열에서 erase(1, 2);를 하게 된다면, 1에
// 해당하는 문자 'b'의 앞에서부터 2문자를 지우게 되어, bc가 지워져 ad가
// 리턴된다.

// string_length 를 도입하여서 정말 편리한 점이 무엇이냐면, 어차피
// string_length뒤에 어떠한 정보가 오든지 별로 신경을 안써도 된다.
// 위와 같이 앞으로 문자들을 끌고 오면서 뒤의 문자들을 초기화 하지 않았지만,
// string_length 값을 처리하였기 때문에 뒤의 문자들에 신경쓰지 않아도
// 됩니다.



// 이제 insert와 erase이외에 매우 빈번하게 사용되는 또 다른 작업으로
// find 함수가 있습니다. 사실 insert, erase, find는 문자열 연산의
// 기초중의 기초라고 불러도 과언이 아닐만큼 필수적인 함수입니다.
// 그렇기 때문에 find 함수 자체를 어떻게 구현하느냐에 따라 문자열 클래스의
// 전반적인 성능이 좌지우지 되는 경우도 있다.

// 왜냐면 insert와 erase는 사실 연산 시간이 크게 오래 걸리지는 않지만
// 문자열의 크기가 매우 크다면 find 연산은 엄청나게 오래 걸릴 수 있게 되니까.

// 문자열을 검색하는 알고리즘은 수없이 많지만, 어떤 상황에 대해서도
// 좋은 성능을 발휘하는 알고리즘은 없습니다. (예를 들어 짧은 문자열 검색에
// 최적화된 알고리즘과 긴 문자열 검색에 최적화 된 알고리즘같이)
// 그렇기에 특별한 알고리즘을 사용하는 경우에는 그 클래스의 사용 목적이
// 명확해서 그 알고리즘이 좋은 성능을 발휘할 수 있는 경우에만 사용하는 것이
// 보통입니다. 따라서 우리의 MyString의 경우, 가장 간단한 방법으로 find
// 알고르즘을 구현하도록 했다.


int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if (str.string_length == 0) return -1;
    for (i = find_from; i < string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) break;
        }

        if (j == str.string_length) return i;
    }

    return -1; // 찾지 못했음
}
// 간단한 find 함수 구현
// find_from 부터 시작해서 string_content와 str가 완벽히 일치하는 부분이
// 생긴다면 그 위치를 리턴하고, 찾지 못할 경우 -1을 리턴하도록
// str1.find(0, "very") 에서는, 맨 처음부터 시작해서 "very"를 찾는다
// "very"를 찾기 위해 이전의 검색한 위치 바로 다음부터 시작하여 또
// "very"를 찾는다.




// 마지막 함수는 문자열 간의 크기를 비교하는 compare 함수.
// 여기서 '크기'를 비교한다는 의미는 사전식으로 배열해서 어떤 문자열이 더
// 뒤에 오는지 판단한다는 의미가 된다. 이 함수를 이용해서 문자열 전체를
// 정렬하는 함수라던지, 기존의 C언어에서 strcmp 함수 등으로 지원하였던
// 것들을 그대로 사용할 수 있게 된다.
// *this와 str을 비교하는 형태.
int MyString::compare(const MyString& str) const {
    // (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다
    // 1은 (*this)가 사전식으로 더 뒤에 온다는 의미. 0은 두 문자열이
    // 같다는 의미, -1은 (*this)가 사전식으로 더 앞에 온다는 의미.

    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i]) return 1;

        else if (string_content[i] < str.string_content[i]) return -1;
    }

    // 여기까지 했는데 끝나지 않았따면 앞 부분까지 모두 똑같은 것이 된다.
    // 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.

    if (string_length == str.string_length) return 0;

    // 참고로 abc와 abcd의 크기 비교는 abcd가 더 뒤에 오게 된다.
    else if (string_length > str.string_length) return 1;

    return -1;
}
// 참고로 말하면 abc와 abcd의 크기를 비교하면 abc가 abcd보다 사전적으로
// 더 앞에 오게 된다. 따라서 이에 대한 처리는 뒤에 따로하게 된다.
// std::min과 std::max함수는 iostream를 include하면 사용할 수 있는
// 함수들이므로, 굳이 만들 필요가 없다.


int main() {
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();
}