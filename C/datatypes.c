/*
char
1byte
signed: -128 to 127
unsigned: 0 to 255

short int
2byte
signed: -32768 to 32767
unsigned: 0 to 65535

int
4byte
signed: -2147483648 to 2147483647
unsigned: 0 to 4294967295

long int(long)
4byte
signed: -2147483648 to 2147483647
unsigned: 0 to 4294967295

bool
1byte
true of false

float
4byte
+- 3.4e += 38 (~7 digits)

double
8byte
+- 1.7e +- 308 (~15 digits)

long double
8byte
+- 1.7e +- 308 (~15 digits)
*/


// 문자를 저장하는 변수
#include <stdio.h>
int main() {
    char a; // 변수 선언
    a = 'a'; // 문자 'a' 대입

    printf("%d", a); // 문자 출력
    // %d: 10진수 // %c 문자
    /*
    ASCII: American Standard Code for Information Interchange
    8비트 데이터 이용 문자(256개)
    => Extended ASCII: 1비트 추가 확장
    => Unicode: 한 문자를 1에서 4바이트까지 다양한 길이로 처리; 새로운 문자 추가
    */

    double celsius; // 8byte
    scanf("%lf", &celsius); // 화면(키보드)로부터 결과를 입력받는 함수
    // %lf: double형(scanf만) 입력(입력할 때는 명시해야함)
    // prinf같은 경우 double, float 모두 %f로 출력
    // scanf_s(): scanf가 입력받는 데이터의 크기를 확인하지 않기 때문에 버퍼 오버플로우
    // (입력받는 데이터의 크기가 준비된 공간보다 큰 문제)가 발생하므로 사용
    printf("%f", celsius);

    char ch; // 문자 1byte
    scanf("%c", &ch); // char형 변수인 ch에 한글을 치면 오류(1바이트만 가능)
    // 허용된 메모리 이상에 데이터를 집어넣어 발생하는 오류를 Buffer Overflow라 하며, 보안상 매우 취약
    // 버퍼 오버플로우를 이용해서 공격자들이 원하는 코드가 실행될 수 있도록 조종 가능
    // 또한, 근처 데이터가 손상됨에 따라 큰 문제가 발생; 허용된 데이터 이상을 집어넣는지 검사할 필요성

    short sh; // 2byte
    int i; // 4byte
    long lo; // 4byte
    scanf("%hd", &sh); // 모두 int와 똑같은 정수형 변수
    scanf("%d", &i);
    scanf("%ld", &lo);

    float fl; // 4byte 실수
    double du; // 8byte 실수
    scanf("%f", &fl);
    scanf("lf", &du);

    return 0;
}