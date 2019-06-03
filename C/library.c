// 자주 쓰는 함수들을 미리 만들어놓았다

// 전처리기 명령 - 컴파일 이전에 정확히 대체됨
#include <stdio.h> // 입출력 라이브러리
#include <string.h> // 문자열 라이브러리

// 매크로
#define VAR 10 // #define 매크로이름 값
#define A
#define B

// ifdef-endif 조건부 컴파일 예시
#define CALCULATOR_MODEL_1

#ifdef CALCULATOR_MODEL_1
float var1, var2;
#else // else도 가능
// do something
#endif
#ifdef CALCULATOR_MODEL_2
double var1, var2;
#endif

int ifdef_test();

int main() {
    char str1[20] = {"hi"};
    char str2[20] = {"hello everyone"};
    char arr[VAR] = {"hi"}; // char arr[10] 과 같다
    
    strcpy(str1, str2);

    printf("str1 : %s \n", str1);

    if (!strcmp(str1, str2)) printf("%s\n", str1);
    else printf("%s\n", str2);

    ifdef_test();

    return 0;
}


int ifdef_test() {
    // ifdef-endif : 조건부 컴파일 => 계산기 모델마다 메모리와 cpu가 달라서 double 또는 float 중 하나를 사용해야할 때같은 경우
    // #ifdef 매크로이름(이 정의되어 있으면) 호출코드 #endif
    #ifdef A
    printf("AAAA \n");
    #endif

    #ifdef B
    printf("BBBB \n");
    #endif

    return 0;
}