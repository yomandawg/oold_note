#include "str.h"
// str.c에서도 굳이 "str.h" 전처리기를 입력하는데
// 여기서 따로 지정한 함수의 밑에 사용할 때 생길 수 있는 오류 미리 사전 방지

char compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) return 0;
        str1++;
        str2++;
    }
    if (*str2 == '\0') return 1;
    return 0;
}

char copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return 1;
}