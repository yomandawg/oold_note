// 문자열로 Complex 수와 덧셈하기
// y = z + "3+i2";
// 이런 문장을 사용하였을 경우 성공적으로 처리할 수 있게 된다느 의미
// 문자열로 복소수를 어떻게 표현해야 할 지 약속이 필요함 위와 같이.
// 허수부의 값이 0이라면 굳이 안써도 되는데(실수부도) double 변수이기
// 때문에 문자열로 입력 받을 때 정수 부분만 받는 게 아니라 소수점 아래
// 부분도 처리해 주어야 할 것

#include <iostream>
#include <string.h>

class Complex {
    private:
        double real, img;

        double get_number(const char *str, int from, int to);

    public:
        Complex(double real, double img) : real(real), img(img) {}
        Complex(const Complex& c) { real = c.real, img = c.img; }
        Complex(const char* str);

        Complex operator+(const Complex& c);
        Complex operator+(const char* str);

        Complex operator-(const Complex& c);
        Complex operator*(const Complex& c);
        Complex operator/(const Complex& c);

        Complex operator-(const char* str);
        Complex operator*(const char* str);
        Complex operator/(const char* str);

        void println() { std:: cout << "( " << real <<  " , " << img " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}

Complex Complex::operator+(const char* str) {
    // 입력받은 문자열을 분석하여 real과 img 부분을 찾는다.
    // 맨 앞의 부호는 생략 가능하다(생략시 +라 가정)

    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;

    // 먼저 가장 기준이 되는 'i'의 위치를 찾는다
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 'i'가 없다면 이 수는 실수다.
    if (pos_i == -1) {
        str_real = get_number(str, begin, end - 1);
        // get_number 함수는 특정 문자열에서 수 부분을 double 값으로
        // 반환하는 함수다. <stdlib.h> 에서 atof 라는 함수랑 같다
        // get_number의 경우 operator+ 함수의 내부적으로 사용되는
        // 함수이므로 굳이 인터페이스로 제공될 필요는 없기에 private이다

        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    // 'i'가 있다면, 실수부와 허수부를 나눠 처리
    str_real = get_number(str, begin, pos_i - 1);
    str_img = get_number(str, pos_i + 1, end - 1);
    // i를 기준으로 왼쪽의 실수부와 오른쪽의 허수부로 나뉜다.
    // 이 때 str_real은 get_number을 이용해 정확히 실수 값을 얻는다
    // 하지만 str_img의 경우 i 앞의 부호 부분이 잘리기 때문에 정확한
    // 실수 값을 얻기 힘들기 때문에 따로
    if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;
    // 로 해서 str_img의 정확한 부호를 처리한다.

    Complex temp(str_real, str_img);
    return (*this) + temp;
}
// 일단 문자열을 덧셈의 피연산자로 사용하게 되므로, operator+의 인자는
// Complex&가 아니라 const char* 가 된다. 입력받은 '문자열 복소수'를
// 분석하기 위해 가장 중요한 'i'의 위치를 먼저 찾는다. 이를 기준으로
// 복소수의 실수부와 허수부가 나뉜다.


double Complex::get_number(const char *str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;
    // 부호 부분 바로 다음부터 처리하도록

    double num = 0.0;
    double decimal = 1.0;
    bool integer_part = true;

    // double형 변수로 입력받은 문자열을 처리할 때 유의할 점은
    // for 문에서 앞자리부터 읽는다는 것
    // 예를 들어 123.456이면 1, 2, 3... 순으로 입력받는다
    // 이때문에 소수점 앞 부분과 뒷 부분의 처리를 다르게 해야한다.
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0; // integer_part가 true일 때
            num += (str[i] - '0');
            // 이 기법은 ASCII 테이블상에서 0부터 9까지 숫자가
            // 크기들로 배열되어있기 때문에 단순히 '0'을 빼면
            // 그 숫자에 해당하는 실제 정수값을 얻을 수 있다!
        } else if (str[i] == '.') integer_part = false;
        else if (isdigit(str[i]) && !integer_part) {
            // decimal이라는 변수에 위치에 따라 나누면서 값을 바꾼다
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else break; // 그 이외의 이상한 문자가 들어올 경우
    }

    if (minus) num *= -1.0;

    return num;
}
// 만일 from 이 to 보다 크다면 올바르지 않은 입력으로 0 반환.(예외 케이스)
// 부호 처리 위해 minus라는 bool 변수 도입으로 마지막에 확인

// +뿐만 아니라 - * 등 모둔 연산자들에 이런 기능을 지원하기 위해
// 코드를 반복적으로 쓰는 것은 매우 귀찮을 것이다. 그래서 불편한 작업을
// 막기 위해 const char *로 오버로딩되는 Complex 생성자를 추가하는 것도
// 나쁘지 않을 것
Complex::Complex(const char* str) {
    // 입력받은 문자열을 분석하여 real과 img 부분 찾는다
    // 맨 앞 부호는 생략한다(생략시 +라 가정)

    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    // 기준이 되는 'i'를 찾는다
    int pos_i = -1;
    for (int i = 0; i != end; i++) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    // 'i'가 있다면 실수부, 허수부 나누어 처리
    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

// 이러면 나머지 함수들도
Complex Complex::operator-(const char* str) {
    Complex temp(str);
    return (*this) - temp;
}
Complex Complex::operator*(const char* str) {
    Complex temp(str);
    return (*this) * temp;
}
Complex Complex::operator/(const char* str) {
    Complex temp(str);
    return (*this) / temp;
}
// 사실 위와 같이 연산자 함수 만들 필요 없구
// 생성자 하나만 만들면 충분하다!!!
// 컴파일러는 매우 똑똑하기 때문에 a = a +"-1.1 + i3.923";
// 와 같은 문장을 사용했을 때 이 문장을 바꿔준다!
// operator+(const Complex& c) 밖에 없기 때문에 직접적으로
// 오버로딩 되지는 않지만, 다음 순위로 오버로딩 될 수 있는 함수들이
// 있는지 없는지 확인한다.
// 놀랍게도 Complex(const char* str); 생성자가 있기에
// 컴파일러는 문자열 리터럴로부터 const Complex 타입의 객체를
// 새롭게 생성할 수 있게 되는것
// 즉 위 문장은
// a = a.operator+(Complex("-1.1 + i3.923")); 으로 변환된다!

// 한가지 짚고 넘어가야 할 점은, 만일 우리가 operator+ 함수의 인자가
// const Complex& c 가 아니라 그냥 Complex& c 로 받도록 하였다면
// 위와 같은 변환은 이뤄지지 않는다. 왜냐면 -1.1 + i3.923 자체가
// 문자열 리터럴이므로, 이를 바탕으로 생성된 객체 역시 상수여야 하기 때문
// 따라서 여러모로 인자의 값을 변형하지 않는다고 확신이 들면 무조건!
// const 인자로 받도록 하는게 좋다.

// a = "-.1. + i3.923" + a; 는 또 성공적으로 컴파일 되지 않는다!
// 왜냐면 a.operator+("-1.1+i3.923")으로 변환돼야 하는데
// 앞에 있는 경우 이 같은 변환이 불가능하기 때문에!