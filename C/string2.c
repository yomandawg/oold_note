#include <stdio.h>

int main() {
    char str[] = "sentence";
    char *pstr = "sentence"; // 주소값(포인터)에 문자열을 넣는다?!
    // "sentence"는 주소값이 맞다! - 문자열이 저장된 주소값(시작 주소)

    printf("str: %s \n", str); // str: sentence
    printf("pstr: %s \n", pstr); // pstr: sentence
    // 리터럴 읽기작업만 하는 경우는 괜찮다
    printf("%d \n", "sentence"); // sentence


    str[1] = 'a';

    // pstr[1] = 'a'; // 오류
    // 포인터를 통해 리터럴의 값을 변경하려고 하면 오류가 난다!

    return 0;
}

/* Literal

소스코드 상에서 고정된 값을 가지는 것을 Literal이라 함
C언어의 경우 ""로 묶인 것을 문자열 리터럴(string literal)

char str[] = "hello"; // 리터럴 공간에서 "hello"를 가져와 str에 대입해라 명령
char *pstr = "goodbye"; // 티러럴 공간에서 "goodbye"의 주소값 가져와서 pstr에 넣어라
printf("why");
scanf("%c", str[0]);
// ""로 묶은 것을 리터럴이라 부르는데, 이는 소스코드 상에서 고정된 값을 가지기 때문
컴퓨터는 이런 리터럴을 따로 모아서 보관함
프로그램을 시작하면 리터럴들이 보관되어 있는 공간이 생김

- 프로그램이 실행돼서 메모리에 로드되면 5가지 영역
=> text segment // data segment // bss segment // heap // stack
- 이 때 text segment에 프로그램 코드, 상수, 리터럴이 정의됨
=> text segment의 내용들은 읽기만 가능함

리터럴의 값은 절대로 변경돼서는 안된다
- 오직 읽기전용에만 보관
- 변경하려고 시도하면 오류

*/


int playing() {
    char str1[] = {"abc"};
    char str2[] = {"def"};
    // str1 = str1 + str2; // 불가능하다
    // 각 배열의 주소값을 더하는 것인데 배열의 이름은 포인터 상수이기때문에 대입 연산 수행시 오류

    // if (str1 == str2) // 불가능
    // "abc"는 리터럴이므로 str1과 "abc"를 비교한다는 것은 str1이 저장된 메모리 상의 주소값과
    // "abc" 문자열 리터럴이 보관된 메모리 상의 주소값을 비교한다는 안됨
    // str1 = str2; // 불가능
    // 대입할 수 없다 => str1의 값은 바뀔 수 없는 포인터 상수이기 때문에 오류 발생
}

// 문자열을 다루려면 다음과 같은 함수들이 필요
// 문자수 세는 함수
// 문자열 복사 함수
// 문자열 합치는 함수
// 문자열 비교 함수

// 문자열 복사
// src의 문자열을 dest로 복사한다. 단, dest의 크기가 반드시 src보다 커야한다
char copy_str(char *dest, char *src) {
    while (*src) { // NULL 문자가 오기 전까진 계속
        *dest = *src;
        src++; // 그 다음 문자를 가리킨다
        dest++;
    }
    *dest = '\0'; // NULL 문자(end of string)
    return 1;
}

// char str[100];
// str = "abcdefg"; // 불가능하다
// str에 문자열 리터럴 "abcdefg" 가 위치한 곳의 주소값을 넣어라 라는 말인데
// 배열 이름은 상수이다. 즉, 배열의 주소값을 바꿀 수 없다!

// char str[100] = "abcdefg"; // 이는 C에서 편의상 제공하는 방법이다: 배열 정의할 때만 사용 가능


// 문자열 합치기
// dest에 src 문자열을 끝에 붙인다. 이 때, dest 문자열의 크기를 검사하지 않으므로 src가 들어갈 수 있는
// 충분한 크기가 돼야 한다.
char stradd(char *dest, char *src) {
    while (*dest) dest++; // dest는 NULL 문자를 가리키고 있게 됨
    while (*src) { // src문자열을 dest의 NULL문자가 있는 곳부터 복사해 넣는다
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; // 마지막으로 NULL 추가
    return 1;
}



// 문자열 비교 함수
char compare(char *str1, char *str2) {
    while (*str1) { // str1의 끝에 도달할 때까지 문자 비교
        if (*str1 != *str2) return 0; // 만약 다르다면 종료
        str1++;
        str2++;
    }
    if (*str2 == '\0') return 1; // str1이 NULL 문자를 맞았을 때, str2도 NULL인가
    return 0; // 그렇지 않다면 false
}