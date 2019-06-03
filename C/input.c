#include <stdio.h>

int main() {
    // 스트림 생성
    FILE *fp = fopen("a.txt", "r"); // "r"형으로 (읽기) 형식으로 연다
    char buf[20];

    // 쓰기 형식은 파일이 존재하지 않으면 새로 만들었지만
    // 읽기 형식은 파일이 없으면 NULL 반환하고 스트림을 만들지 않는다
    if (fp == NULL) {
        printf("READ ERROR! \n");
        return 0;
    }
    fgets(buf, 20, fp); // 문자 받기
    // (어디, 몇바이트, 어떤 스트림)
    // fgets는 scanf와 다르게 몇바이트를 받을지 안정적으로 결정할 수 있다
    printf("%s\n", buf);
    fclose(fp);
    return 0;
}


int oneatatime() {
    FILE *fp = fopen("a.txt", "r");
    char c;

    // fgetsc는 fp에서 문자를 하나 얻어옴(한 문자씩 읽어옴)
    // 문자열 맨 마지막이 NULL 문자로 종료를 나타내는 것처럼
    // 파일의 맨 마지막에는 EOF라고 End of File을 나타내는 -1 값이 있음
    // #define EOF (-1) 으로도 돼있다
    while ((c = fgetc(fp)) != EOF) { // c가 EOF인지 아닌지 비교를 통해 파일의 끝까지 입력을 받았는지 안받았는지 알 수 있다
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}


int filesize() {
    FILE *fp = fopen("a.txt", "r");
    int size = 0;

    while (fgetc(fp) != EOF) {
        size++; // 계속 size를 증가시켜서 파일의 크기를 알아내는 것
    }

    printf("%d \n", size);
    fclose(fp);

    return 0;
}

/* 파일 위치 지정자
여태까지 파일에서 입력을 받을 때 언제나 파일의 시작부분에서 끝 부분으로 쭉 받음
즉, 이전에 입력받은 데이터는 다시 입력받지 않는다
이것이 가능하게 된 이유는 파일 위치 지정자(Position Indicator) 때문

만일 a.txt 에 abcdefg가 있고 fgetc로 입력을 받는다고 해보면
파일을 맨 처음 열었을 때에는 파일 위치 지정자는 파일의 맨 첫부분을 가리키고 있다.
따라서 a를 가리키고 있다고 보아도 무방하다.
이제 fgetc로 입력을 받는다면 파일 위치지정자는 한 칸 넘어가서 다음에 입력받을
것을 가리키고 있다.
fgetc를 한 번 더하면 a를 다시 입력 받는 것이 아니라 그 다음인 b를 입력받음
그리고 또 파일 위치 지정자는 또 한 칸 이동해서 c를 가리킴

그런데 만약 abcd까지 파일입력을 받았는데 다시 처음부터 입력받고 싶다면 어떻게 해야하나?

두 가지 방법
1. fopen으로 파일을 다른 스트림으로 또 여는 것
2. 파일 위치지정자를 옮기는 것

*/

int test() {
    FILE *fp = fopen("a.txt", "r");
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    fgetc(fp);
    // d까지 입력받았으니 이제 position indicator은 e를 가리킨다
    fseek(fp, 0, SEEK_SET);
    // 파일 위치지정자를 SEEK_SET으로 부터 0번째 떨어진 곳,
    // 즉 SEEK_SET으로 돌린다
    // SEEK_SET은 파일의 맨 처음을 일컫는 매크로 상수
    // SEEK_CUR은 현재의 위치
    // SEEK_END는 마지막의 위치
    printf("%c\n", fgetc(fp)); // a 를 입력받게 된다
    fclose(fp);
    return 0;
}


int test2() {
    FILE *fp = fopen("a.txt", "w");
    // 문자열을 파일스트림 fp에 넣는다
    fputs("Psi is an excellent C programmer", fp);
    fseek(fp, 0, SEEK_SET); // 파일 위치지정자를 맨 처음으로 돌린다
    fputs("is Psi", fp); // fputs를 다시 하면 앞에 끼워져 들어가는게 아니라
    // 이전의 내용을 덮어쓰기 하면서 기록이 된다!!
    fclose(fp);
    return 0;
}