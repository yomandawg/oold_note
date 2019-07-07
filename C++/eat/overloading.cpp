/* 
if (str1 == str2) 등 의 작업을 할 수 없다!
+, -, ==, [] 등의 기본 연산자는 모두 C언어에 기본적으로 정의되어 있는
데이터 타입(int, float)등에서만 사용 가능한 것이므로! 이들을 구조체 변수에
// 사용한다는 것은 불가능하였다.

하지만 C++에선 사용자 정의 연산자를 사용할 수 있다!!!
// ::(범위 지정), .(멤버 지정), .*(멤버 포인터로 멤버 지정)을 제외한
// 모든 연산자를 사용할 수 있다!
// >=, == 와 같은 비교 연산자 && 같은 논리 연산자, -> 같은 멤버 선택 연산자
// ++, -- 증감연산자, [], () 등 함수 호출 연산자 등 모두 직접 만들 수 있다.

이를 연산자 오버로딩(overloading)한다고 한다.
// 이전에 같은 함수를 인자만 다르게 사용하는 것을 '함수를 오버로딩 했다'
라고 불렀던 것처럼 기본 연산자를 직접 설계한 클래스에 맞게 직접 사용하는 것을
'연산자 오버로딩' 이라고 한다.

일단 연산자 오버로딩을 사용하기 위해서는, 다음과 같이 오버로딩을
원하는 연산자 함수를 제작해야함
(리턴 타입) operator(연산자) (연산자가 받는 인자)

참고로 위 방법 외에는 함수 이름으로 연산자를 절대 넣을 수 없다!
예를 들어 우리가 ==를 오버로딩 하고 싶다면, == 연산자는 결과값이
언제나 bool이고, 인자로는 ==로 비교하는 것 하나만 받게 된다.
따라서 다음과 같이 함수를 정의하면 된다.
bool operator==(MyString& str);

이제 우리가 str1 == str2 라는 명령을 한다면 이는
str1.operator==(str2)로 내부적으로 변환되서 처리됨.
그리고 그 결과값을 리턴하게 된다. 사실 operator==를 만드는 것 자체는
별로 어려운 일은 아니다. 왜냐면 이미 MyString에서 compare라는 좋은
함수를 제공하고 있기 때문.
*/
// 예)
bool MyString::operator==(MyString& str) {
    return !compare(str); // str과 같으면 compare에서 0을 리턴
}
// 여기서 !compare(str)을 리턴하는 이유는 compare함수에서 str과
// *this 가 같으면 0을 리턴하도록 하였는데, operator==은 둘이 같으면
// true를 리턴해야 되기 때문.
// 따라서 NOT 연산자인 !를 앞에 붙여서 리턴하면 올바르게 작동함