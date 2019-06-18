/* [] 연산자 첨자 연산자 overload
배열의 원소를 지정할 때 [] 안에 넣는 수를 첨자(subscript)라고 부름

operator[] 함수는 자명하게도 인자로 몇 번째 문자인지, int 형변수를
인덱스로 받게 된다

즉,

char& operator[](const int index);

char&를 인자로 리턴하는 이유는
str[10] = 'c'; 와 같은 명령을 수행하기 때문에, 그 원소의 레퍼런스를
리턴하게 되는 것.

Char& MyString::operator[](const int index) { return string_content[index]; }

위와 같이 index 번째의 string_content를 리턴해서, operator[]를 사용하는
사용자가 이의 레퍼런스를 가질 수 있게 된다.
 */

/* int Wrapper 클래스 - 타입 변환 연산자
Wrapper 클래스는 무언가를 포장하는 클래스라는 의미
기본 자료형을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것
 */
Class int {
    int data;

    public:
        Int(int data) : data(data) {}
        Int(const Int& i) : data(i.data) {}
}
/*
위 Int 클래스에 int형 자료형을 보관하는 data라는 변수를 정의하면
int형 데이터를 저장한는 객체로 Int 클래스를 사용할 수 있다.
우리는 이 Int 객체가 int의 Wrapper 클래스 객체인 만큼,
int와 정확히 똑같이 작동하도록 만들고 싶다.

Int x = 3; 같이.
int a = x + 4; 도 되도록

이를 잘 수행하도록, 오버로딩을 사용
모든 연산자 함수들을 만들어주면 되나?
하지만 이것은 비효율적

이 wrapper 클래스 객체끼리 하는 일은 단순히 int형 변수끼리 하는 일과
정확히 똑같기 때문에 이미 제공하는 기능을 다시 만드는 것은 비효율적

컴파일러가 이 객체를 마치 int형 변수처럼 생각하도록 하게끔 하자.

operator을 정의하지 않더라도 int형 변수로 변환한 다음 처리하게끔
타입 변환 연산자를 사용!

operator (변환하고자 하는 타입) ()

operator int() 와 같이

주의할 점은 ,생성자 처럼 함수의 리턴타입을 써주면 안된다.
즉,

operator int() { return data; }

단순히 data를 리턴해주면 된다.

컴파일러가 적잘한 operator을 찾아서 변환해 처리.

문제는 대입시에 발생! 디폴트 대입 연산자가 이 역시 알아서 처리해준다.
 */

/*
전위/후위 증감 연산자

++ -- 연산자

a++;
++a;
두 연산자 모두 operator++인데 어떻게 구분하냐?

operator++();
operator--();
이 위는 ++x, --y를 오버로딩 한다

operator++(int x);
operator--(int x);는
후위 연산자 x++, x--를 오버로딩한다.

x는 의미가 없지만 단순히 전위 후위를 구분하기 위해 쓴다.

중요한 점은 전위 증감 연산의 경우 값이 바뀐 자기 자신을 리턴,
후위 증감의 경우 값이 바뀌기 이전의 객체를 리턴

int x = 1;
func(++x); 는 func에 2가 전달

int x = 1;
func(x++); 는 func에 1이 전달

A& operator++() {
    // A++를 수행한다
    return *this;
}
전위 연산자는 ++에 해당하는 연산 수행 후에 반환

A& operator++(int) {
    A temp(A);
    // A++를 수행
    return temp;
}
++를 하기 전에 객체 반환, 즉 temp 객체를 만들어서 이전 상태를 기록한 후에,
++를 수행한 뒤에 temp 객체를 반환한다.

따라서 후위 증감 연산의 경우 추가적으로 복사 생성자를 호출하기 때문에
전위 증감 연산보다 더 느리다!!!
 */

/*
두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌 외부 함수로
오버로딩 하는 것이 좋다
Complex의 operator(const Complex&, const Complex&)와 같이

두 개의 객체 사이의 이항 연산자이지만 한 객체의 값이 바뀐다던지
등의 동등하지 않는 이항 연산자는 멤버 함수로 오버로딩하는 것이 좋다
operator+=는 이항연산자이지만 operator+=(const Complex&)가 낫다

단항 연산자는 멤버 함수로 오버로딩하는 것이 좋다
operator++의 경우.

일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 한다.
 */