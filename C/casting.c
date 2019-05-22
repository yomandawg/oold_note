// 각 변수들에는 고유의 형(type)이 있다.
// 다른 변수끼리 대입을 하는 연산이 필요할 때, 형변환을 할 수 있다.


#include <stdio.h>

int main() {
    int a;
    double b;
    
    b = 2.4;
    a = b; // 에러 - double로부터 int로 형변환: 데이터 손실
    // a에 2.4를 대입했지만
    printf("%d", a); // a는 2로 출력됨
    // double형 변수를 대입하면 소수 부분이 잘려서 정수 부분만 들어가게 된다

    // 형변환
    int c;
    double d;

    d = 2.4;
    c = (int)d; // 형변환 - type casting
    printf("%d", a);

    int _a, _b;
    float _c, _d;
    scanf("%d %d", &_a, &_b);
    _c = _a/_b; // a, b가 정수형이므로 몫만 계산
    _d = (float)_a/_b; // 실제 실수형 나눗셈 수행
    printf("%f %f", _c, _d); 

    return 0;
}

// 컴퓨터가 실수를 표현하는 원리
// 정수 int: 4byte: (2^32-1) 0~2147483647

// 소수: 두가지 방식
// 고정 소수점(Fixed point)

// 부동 소수점(Floating point)
// 대부분 채택: 매우 큰 수를 표현 가능
// f * b^e 로 표현
// f는 가수, b는 밑, e는 지수
// 123의 경우:  f = 1.23 // b = 10 // e = 2
// 가수 부분이 f비트, 지수 부분이 e비트, 맨 앞의 1비트가 sign 비트
// => 가수 23비트, 지수 8비트, 부호 1비트 => 4바이트