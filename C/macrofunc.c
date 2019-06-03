/* 매크로 함수

*/

#include <stdio.h>
// preprocessor #define은 어떤 것을 다른 것으로 치환하는 것
// #define square(x) x * x // #define 함수이름(인자) 치환할 것
// square이라는 이름의 매크로 함수고 인자 x를 x * x로 치환한다는 의미
#define square(x) (x) * (x) // 우선순위 계산 방지

// #define RADTODEG(x) (x) * 57.295
#define RADTODEG(x) ((x) * 57.295) // 나눗셈 우선순위도 방지

// 어떤 인자 앞에 #를 붙이면 인자를 문자열로 바꾼다
#define PrintVariableName(var) printf(#var "\n");
// printf("var" "\n") // C에서 연속한 두개의 문자열은 하나로 합쳐진다
// printf("var\n") 과 동일

// #나 ##는 모두 전처리기문에서만 사용 가능!!(#define)
#define AddName(x, y) x##y // ## 입력된 것을 하나로 합쳐주는 역할


int main(int argc, char **argv) {
    printf("square(3) : %d \n", square(3)); // 9
    // 3 * 3과 같은 결과
    // 매크로 함수라 부르는 이유는 함수와 비슷하기 때문
    // 하지만 int square(x)와는 다르다.
    // 매크로 함수의 경우 문장이 컴파일 전에 전처리기에 의해 위의 square(3) 문장을 3*3으로 바꾼다
    // 함수 호출을 안하고 그냥 바꿈!!

    printf("square(3 + 1) : %d \n", square(3 + 1)); // 7
    // 4*4가 나오지 않고 7?!
    // 3 + 1 * 3 + 1 이 계산된다 (문장을 그냥 치환한다!)
    // square(x) (x) * (x) 로 정의하면 방지됨

    printf("5 rad는: %f 도", 1 / RADTODEG(5));
    // 1 / 5 * 57.295로 된다 => 1 / (5 * 57.295) 여야되는데!
    // 이를 위해 전체 수식을 소괄호로 감싸 ((x) * 57.295)로 하면 된다.

    int a;
    PrintVariableName(a); // printf("a\n");

    int AddName(a, b); // 전처리기에 의해 int ab;로 바뀜
    ab = 3; // 너무 남용하지는 말자! 괄호를 제대로 쓰지 않아 생기는 오류같은 것들은 디버깅하기 어려워
    printf("%d \n", ab);

    return 0;
}