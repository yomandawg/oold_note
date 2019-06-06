/* 함수 오버로딩 (overloading)

함수에 과부하(?)를 주는 것
C에선 하나의 이름을 가지는 함수는 딱 1 개만 존재할 수 있기 때문에 과부하 성립이 안딤
BUT, C++에선 같은 이름을 가진 함수가 여러개 존재해도 된다.(함수 이름에 과부하)

이를 어떻게 구분하는 것인가?
*/

#include <iostream>

// C 컴파일러에서는 오류지만 C++에선 이름이 같더라도 인자가 다르면 다른 함수라고 판단
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

void yo(int x) { std::cout << "int : " << x << std::endl; }
void yo(double x) { std::cout << "double : " << x << std::endl; }

int main() {
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    // 각각 인자의 형이 다르므로 다른 함수가 호출된 것
    // 즉, 적합한 인자를 가지는 함수를 찾아서 호출하게 되는 것
    print(a);
    print(b);
    print(c);

    // char을 받는 함수가 없는데?!면 자신과 최대로 근접한 함수를 찾게 된다
    yo(a);
    yo(b); // char을 int로 변환해 출력한다! 무려!
    yo(c);

    // C++ 컴파일러 함수 overloading
    // 1. 자신과 타입이 정확히 일치하는 함수를 찾는다.
    // 2. 일치하는 타입이 없는 경우, 
    //      char, unsigned char, short는 int로 변환
    //      unsigned short는 int의 크기에 따라 int 또는 unsigned int로 변환
    //      float은 double로 변환
    //      enum은 int로 변환
    // 3. 위와 같이 변환해도 일치하지 않는다면,
    //      임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환 (예: float -> int)
    //      enum도 임의의 숫자 타입으로 변환 (예: enum -> double)
    //      0은 포인터 타입이나 숫자 타입으로 변환
    //      포인터는 void 포인터로 변환
    // 4. 유저 정의된 타입 변환으로 일치하는 것을 찾는다
    
    // 만약 컴파일러가 위 과정을 통해 일치하는 함수를 찾을 수 없거나
    // 같은 단계에서 두 개 이상이 일치하면 모호하다(ambiguous) 오류 발생

    return 0;
}
