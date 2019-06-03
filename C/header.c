/*
프로그램의 모듈화
- 파일을 여러개로 나눠야할 필요성
*/

#include <stdio.h>
#include "str.h"
// 전처리기(Preprocessor) 명령어
// => 컴파일 이전에 실행됨 => 파일의 내용을 정확히 복붙해온다
// => <>는 컴파일러에서 기본으로 지원하는 헤더
// => ""는 임의제적 헤더

// char compare(char *str1, char *str2); // 컴파일러가 찾아서 가져옴

int main() {
    char str1[20];
    char str2[20];

    scanf("%s %s", str1, str2);

    if (compare(str1, str2)) printf("%s %s\n", str1, str2);
    else printf("%s %s\n", str2, str1);

    return 0;
}

// 컴파일러는 실행파일을 만들기 위해 c코드를 컴퓨터가 이해할 수 있는 언어로 바꿈
// 어셈블리(기계어와 1:1 대응)로 변환 => 목적코드로 불리는 확장자 .o 파일 생성
// 이 과정 후 linking을 통해 각기 다른 파일에 위치한 소스 코드들을 엮어서
// 실행 파일로 만듦 => gcc header.c str.c