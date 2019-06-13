/* complex number
MyString 자체가 너무 비대한 바람에 새로운 클래스를 만들 것
바로 복소수 (Complex Number)을 다루는 클래스

표준 라이브러리(std)에 std::complex가 정의되어 있어서 굳이 만들지
않아도 되지만 교육용임

실수의 제곱은 언제나 양수이기 때문에 괜찮지만 음수의 제곱근은 실수로
표현하지 못한다. 따라서 imaginary number이라 부르며 수학적으로만 존재

복소수는 즉 z = a+bi로 표현 (a, b는 실수)

우리가 만들고자 하는 것은 이 복소수를 나타내는 클래스를 구성하겠다는 이야기
임의의 복소수 하나를 표현하기 위해서 두개의 값(실수부 허수부)가 필요하기
때문에 반드시 클래스로 구현해야함.
 */

#include <iostream>

class Complex {
    private:
        double real, img;

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }


        // Complex plus(const Complex& c);
        // Complex minus(const Complex& c);
        // Complex times(const Complex& c);
        // Complex divide(const Complex& c);
        // a.plus(b.divide(c)).plus(d); 직관적이지 않다!

        Complex operator+(const Complex& c);
        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex& operator=(const Complex& c);
        // 기본적으로 대입 연산자 함수는 기존 사칙연산 함수와는 다르게
        // Complex& 타입을 리턴한다.
        // 대입 연산자 자체의 의미를 생각해 볼 때, 리턴값을 void로
        // 해도 무방하지만, 프로그래머들은 종종 if((i = x) < y)와
        // 같은 문장을 사용하므로 리턴값을 주는 것이 인터페이스 차원에서
        // 더 낫다.

        // 이 때 Complex 타입을 리턴하지 않고 굳이 Complex& 타입을
        // 리턴하냐면, 대입 연산 이후에 이 값을 가지고 다른 연산을
        // 수행하지는 않기 때문, 예를 들어 (i = 3) + 4와 같은 명령을
        // 내리지는 않는다. 그렇기에 값에 의한 복사가 발생하는 것 보다
        // 레퍼런스를 리턴하는 것이 올바르다.

        // 마찬가지로 다른 사칙연산 대입 함수들 구현 가능
        Complex& operator+=(const Complex& c);
        Complex& operator-=(const Complex& c);
        Complex& operator*=(const Complex& c);
        Complex& operator/=(const Complex& c);

        void println() { std::cout << "( " << real << ", " << img << " ) " << std::endl; }
};

// 복소수는 언제나 실수부, 허수부로 나뉘어지므로, Complex 클래스 역시
// 실수부의 값과 허수부의 값을 나타내는 real과 img 변수가 있습니다.
// 여기서 문제는 이전에 만들었던 MyString과는 다르게, 사칙 연산이
// 엄청나게 자주 쓰인다는 것입니다. 당연하게도 문자열의
// 덧셈(+연산) 까지는 생각할 수 있었따 해도, 곱셈이나 나눗셈 연산
// 자체는 고려할 필요가 없는데, 복소수의 경우 당옇니 클래스 인터페이스
// 차원에서 곱셈과 나눗셈을 지원해야한다.

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
        (img * c.real - real * c.img) / (c. real * c.real + c.img * c.img));
    return temp;
}
// 위 4개 연산자 함수 모두 Complex&가 아닌 Complex를 리턴하고 있다.
// ref가 아닌 이유는 Complex를 리턴하는 연산자 함수는 값의 복사가 일어나기 때문에
// 속도 저하가 발생하지만 위 처럼 레퍼런스를 리턴하게 되면 값의 복사 대신
// 레퍼런스만 복사하는 것이므로 속도 저하는 나타나지 않는다. 하지만, 위와 같이
// operator+를 정의할 경우 다음 문장이 어떻게 처리되는지 생각해보면,
// Complex a = b + c + b; (의도는 a = 2 * b + c);
// 실제로 처리되는 것을 보자면 (b.plus(c)).plus(b)가 되는데, b.plus(c)
// 를 하면서 b에는 b + c 가 들어가고 거기에 다시 plus(b)를 하면 값 자체만
// 보자면 2 * b + 2 * c 가 된다. 이러한 문제를 막기 위해 반드시
// 사칙 연산의 경우 값을 리턴해야 함.

// 또한 함수 내부에서 읽기만 수행되고 값이 바뀌지 않는 인자들에 대해는
// const 키워드를 붙여주는 것이 바람직하다. operator+의 경우,
// c의 값을 읽기만 하지 c의 값에 어떠한 변화도 주지 않으므로
// const Complex& 타입으로 인자를 받는다.

// 인자의 값이 함수 내부에서 바뀌지 않는다고 확신할 때 const 키워드를
// 붙여준다. 이는 나중에 발생할 수 있는 실수를 줄인다.

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}
// 사실 굳이 operator=을 만들지 않더라도, 소스를 컴파일하면 잘 작동함
// 이는 컴파일러 차원에서 디폴트 대입 연산자(default assignment operator)
// 을 지원한다. 이전에 복사 생성자를 다룰 때 디폴트 복사 생성자가 있었던 것과 일맥상통

// 디폴트 복사 생성자와 마찬가지로 디폴트 대입 연산자 역시 얕은 복사를 수행
// 따라서 깊은 복사가 필요한 클래스의 경우 (예를 들어, 클래스 내부적으로
// 동적으로 할당되는 메모리를 관리하는 포인터가 있다던지) 대입 연산자
// 함수를 꼭 만들어줘야 할 필요가 있다.

/*
SomeClass a = b;

SomeClass a;
a = b;

이 둘의 차이는 1 의 경우 아예 a 의 복사 생성자가 호출되는 것이고,
2의 경우 그냥 기본 생성자가 호출된 다음, 다음 문장에서 대입 연산자 함수가
실행되는 것
 */

// 그 외 대입함수의 내부구현은 미리 만들어놓은 함수들로 처리
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

// 참고로 연산자 오버로딩을 사용하면 a += b 와 a = a + b;가 같다고
// 보장되지 않는다! 컴파일러는 operator+와 operator=를 정의해놓았다고
// a += b를 자동으로 바꿔주지 않음. 이는 ++나 -- 또한 해당.
// 모든 면산자들에 개별적인 정의 필요

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a * b;

    c.println();
}