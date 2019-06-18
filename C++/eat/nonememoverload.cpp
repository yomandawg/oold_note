/*
a = a + "-1.1 + i3.923";
는 컴파일되지만
a = :-1.1 + i3.923" + a;
는 컴파일되지 않는다. 왜냐면, 1의 경위 a.operator + (complex)로 변환될 수 있지만
2는 그렇지 않기 때문. 원칙적으로 클래스를 사용하는 사용자의 입장에서
1이 된다면 2도 당연히 돼야한다. 그래야 연산자 오버로딩 명분이 확실하다.

다행히도 컴파일러는 이항연산자(피연산자 두개를 취하는 연산자)
- 예를 들어 +, -, *, /, ->, = 등을 다음과 같은 두 개의 방식으로 해석한다

어떤 임의의 연산자 @에 대해서 a@b는
*a.operator@(b);
*operator@(a, b);
두가지로 해석된다.

참고로 이는 일부 연산자들에 대해는 해당되지 않는데, 대표적으로 [] 연산자
-> 연신자 , =, () 연산자 등. 의 경우 멤버 함수로만 존재 가능
즉, 따로 멤버 함수가 아닌 전역 함수로 뺄 수 없다.

즉, 컴파일 시에 둘 중 하나의 가장 가까운 것을 택해서 처리된다.
a.operator@(b)에서의 operator@는 a의 클래스의 멤버 변수로써 사용되는
것이고, operator@(a, b)에서의 operator@는 그냥 일반적인 함수를 의미

따라서 이를 처리하기 위해 함수를 정의하면,

Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a);
    return temp.operator+(b);
}

우리의 또 다른 operator+는 두 개의 const Complex& 타입의 인자 a, b를
받게 된다. 앞에서도 말했지만 컴파일러는 정확히 일치 하지 않는 경우,
가장 가까운 '가능한' 오버로딩 되는 함수를 찾게 되는데,
마침 우리에겐 Complex(const char *) 타입의 생성자가 있으므로

"-1.1 + i3.923" + a; 는

operator+(Complex("-1.1 + i3.923"), a); 가 되어서 실행된다.

근데 왜 굳이 귀찮게 temp라슨 새로운 Complex 객체를 정의하여서
temp 와의 + 연산ㅇㄹ 리턴하느냐이다. 그냥 a + b할 것을 불필요하게
복사 생성을 한 번 더하게 돼서 성능의 하락이 발생하게 되냐?

하지만 그냥 a + b를 하게 된다면 경고 메세지.

즉 a + b에서 a.operator+(b)가 호출되는게 아니라, operator+(a, b)가
호출되기 때문에 재귀적으로 무한히 많이 함수가 호출되어 오류가 발생하는
것이다. 실제로 실행해보아도 프로그램이 강제로 종료되는 모습을 볼 수 있다.

따라서 이와 같은 문제를 방지하기 위해 우린 다음과 같이 강제로 멤버 함수
operator+를 호출하도록 지정

즉 a 가 const Complex인데, 우리가 호출하고자 하는 멤버 함수 operator+
는 const 함수가 아니기 때문. 상당히 골치 아픈 문제다.

const객체는 언제나 값이 바뀔 수 없으며, 만일 const 객체의 멤버 함수
호출 시에는 그 함수가 객체의 값을 바꾸지 않는다고 보장 할 수 있도록
const 함수여야 한다. 하지만 멤버 함수 operator+는 const 성이 없으므로
operator+를 호출하는 것은 불가능해진다.

이 문제를 해결할 수 있는 유일한 방법은 Complex operator+내부에서
다른 함수들을 호출하지 않고 직접 덧셈을 하면 된다. 다만 이 방법도
문제가 있따. 멤버 함수가 아닌 외부 함수 operator+에서 객체의
private 정보에 접근할 수 있어야만 하는데, 이게 불가능
그래서 friend 키워드를 사용
 */

#include <iostream>

class Complex {
    private:
        double real, img;
        double get_number(const char* str, int from, int to);

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        Complex& operator=(const Complex& c);

        friend Complex operator+(const Complex& a, const Complex& b);

        friend ostream& operator<<(ostream& os, const complex& c);

        void println() {
            std::cout << "( " << real << " , " << img << " ) " << std::endl;
        }      
};

// 위와 같이 friend 를 써서 함수는 이제 Complex의 friend가 된다.
// 즉, Complex 클래스의 입장에선 자신의 친구인 operator+에게 모든 정보에
// 접근할 수 있도록 허가하는 것

// private냐 public이냐에 관계 없이 Complex operator+함수는 이제 어떤
// Complex객체라도 그 내부 정보에 접근 가능

Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;    
}

// 이 operator+ 함수는 마치 Complex 클래스의 멤버 변수인양, 객체 정보에
// 접근 가능. real 변수는 private이지만 a.real을 해도 된다.
// 이렇게 된다면 이전의 operator+에서 불필요하게 temp 객체를 생성했던
// 것과는 달리 필요한 것만 사용 가능

// 다른 클래스 자체도 friend로 지정 가능
class A {
    private:
        int x;

        friend B;
};
class B {
    private:
        int y;
};
// A는 B를 friend로 지정하게 된다.
// 주의할 것은 짝사랑 관계이다. 즉, A는 B에게 모든 것을 공개한다.

// 즉 클래스 B에서 A의 private 변수인 x에 접근할 수 있게된다.
// 하지만 B에는 A를 지정하지 않았으므로 A에게 내용을 공개하지 않는다.

/* 입출력 연산자 오버로딩
std::cout << a;라고 하는 것은 사실
std::cout.operator<<(a)를 하는 것과 동일한 명령

즉, 어떤 std::cout이라는 객체 멤버 함수 operator<<가 정의되어있어,
a를 호출하게 되는 것이다.

그런데 std::cout이 int나 double변수, 심지어 문자열까지 자유자재로
operator<< 하나로 출력할 수 있었던 이유는 그 많은 수의
operator<<함수들이 오버로딩 되어 있따는 뜻이다.

실제로 우리가 include하는 iostream헤더파일의 내용을 살펴보면
엄청난 수의 operator<<가 정의되어 있는 것을 알 수 있다.

이들 덕분에 우리가 편하게 인자의 타입에 관계없이 손쉽게

출력을 사용할 수 있게 되는 것.

그러면 우리의 Complex 클래스에서 ostream클래스의 연산자 operator<<를
자유롭게 사용하려면?

Complex c;
std::cout << c;

Complex c;
c.println();을 한 것과 같은 효과를 낸다.
표준 헤더파일의 내용을 수정할 수는 없기 때문에,
operator<<전역 함수를 하나 정해서 Complex의 friend로 지정한 다음 사용
 */

std::ostream& operator<(std::ostream& os, const Complex& c) {
    os << "( " << c.real << " , " << c.img << " ) ";
    return os;
}

/*
여기서 왜 std::cout이 아니고 os라고 의문을 가질 수 있는데,
std::cout 자체가 iostream에서 만들어 놓은 ostream이다.
따라서 ostream& 타입으로 std::cout 객체를 받아 출력하면 된다.

마찬가지로 Complex 내부에서 friend 선언을 해주면 된다.
참고로 operator<< 에서 ostream& 을 리턴하는 이유는 다음의 문장때문에
 */

std::cout << "a의 값은 : " << a << " 이다. " << std::endl;

/*
<< 연산자는 왼쪽부터 오른쪽 순으로 실행되기 때문에 가장 먼저
std::cout.operator<<("a의 값은?") 이 실행되고, 그 자리에
std::cout 이 다시 리턴된다. 그 다음에는 std::cout.operator<<(a);
가 돼서 쭉쭉 이어질 수 있도록 ostream&를 리턴하게 되는 것.
 */





#include <cstring>
#include <iostream>

class Complex {
    private:
        double real, img;
        
        double get_number(const char* str, int from, int to);
    
    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        Complex& operator=(const Complex& c);

        friend Complex operator+(const Complex& a, const Complex& b);
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);

        void println() {
            std::cout << "( " << real << " , " << img << " ) " << std::endl;
        }
};
std::ostream& operator<<(std::ostream& os, const Complex& a) {
    os << "( " << c.real << " , " << c.img << " ) ";
    return os;
}
Complex operator+(const Complex& a, const Complex& b) {
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
}
Complex::Complex(const char* str) {
    // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾는다
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 기준이 되는 i의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // i가 없다면 이 수는 실수다.
    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    // i가 있다면 실수부와 허수부를 나눠 처리한다.
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.') integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else break;
    }

    if (minus) num *= -1.0;

    return num;
}
Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) {
  Complex temp(
      (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
      (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}
Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c) {
  (*this) = (*this) - c;
  return *this;
}
Complex& Complex::operator*=(const Complex& c) {
  (*this) = (*this) * c;
  return *this;
}
Complex& Complex::operator/=(const Complex& c) {
  (*this) = (*this) / c;
  return *this;
}
Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
    Complex a(0, 0);
    a = "-1. 1 + i3.923" + a;
    std::cout << "a의 값은 : " << a << " 이다. " << std::endl;
}