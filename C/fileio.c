/* 파일 위치 지시자
File Position Indicator

스트림의 기본 모토: 순차적으로 입력받는다
앞에 있는 데이터를 먼저 순서대로 읽게 된다. => 파일 위치 지시자

*/

#include <stdio.h>

int main() {
    FILE *fp = fopen("some_data.txt", "r");
    char c;

    if (fp == NULL) {
        printf("error\n");
        return 0;
    }

    while ((c = fgetc(fp)) != EOF) printf("%c", c);
    // fgetc(fp)를 실행할 때 마다 다음 문자를 입력받는다
    // 다음에 입력받을 위치를 미리 표시해 놓는 것 => 파일 위치 지시자
    // stream 시작시 처음 위치에서

    char data[10];

    // fp가 "There is"일 시,
    fgets(data, 5, fp); // fp로부터 \n이나 -1만큼 입력받을 때까지 입력
    // 원래 데이터보다 +1 만큼 입력을 받는데, "Ther" 다음 맨 뒤에
    // NULL \0 문자를 위한 자리
    // 다 받은 후 파일위치지정자는 e를 가리킴

    // 파일 위치자 마음대로 바꿀 수 있는 함수: fseek
    fseek(fp, -1, SEEK_CUR);
    // 현재 파일 위치 지정자의 위치(SEEK_CUR)에서 왼쪽으로(-1) 1만큼

    fclose(fp);
}


int test() {
    FILE *fp = fopen("data.txt", "r");
    char data[10];
    char c;

    if (fp == NULL) {
        printf("error");
        return 0;
    }

    fseek(fp, -1, SEEK_END);
    // 파일 위치 지정자를 파일의 맨 끝(SEEK_END = EOF)에서 한 칸 왼쪽으로

    c = fget(fp);
    printf("%c\n", c);
    fclose(fp);
}


int test3() {
    FILE *fp = fopen("some_data.txt", "r+");
    // 읽기+쓰기로 열겠다, 존재하지 않으면 NULL(새로 안만듦)
    // w+면 읽기+쓰기로 열겠다, 존재하지 않으면 파일 새로 만듦, 존재한다면 내용 다지움

    char data[100];

    fgets(data, 100, fp); // 파일의 내용들을 읽어들인다(최대 100바이트까지)
    // 파일의 위치 지정자가 파일의 맨 100바이트이후를 가리키고 있을 것

    printf("%s\n", data);

    fseek(fp, 5, SEEK_SET);
    // 파일의 맨앞(SEEK_SET)에서 +5로 위치지정자 이동

    fputs("is nothing on this file", fp);
    // 위치지정자부터 string이 차지하는 만큼 덮어씌우기

    fclose(fp);
}


int test3() {
    FILE *fp = fopen("data.txt", "r+");
    char c;

    if (fp == NULL) {
        printf("fail\n");
        return 0;
    }

    // 스트림 작업에서 읽기/쓰기 변환시에는
    // fflush 함수를 호출하거나, fseek, frewind 등의 함수 호출을 통해
    // 파일 위치 지정자를 다시 설정해줘야 한다.
    while ((c = fgetc(fp)) != EOF) {
        if (65 <= c && c <= 90) { // c가 대문자일 경우
            fseek(fp, -1, SEEK_CUR); // 한 칸 뒤로 가서
            fputc(c + 32, fp); // 소문자 c 출력
            fseek(fp, 0, SEEK_CUR);
            // 쓰기-읽기 모드 전환을 위해 fseek함수와 같은 파일 위치 지정자
            // 설정 함수를 호출해야 한다.
        } else if (97 <= c && c <= 122) { // c가 소문자일 경우
            fseek(fp, -1, SEEK_CUR); // 한 칸 뒤로 가서
            fputc(c - 32, fp); // 대문자 c 출력
            fseek(fp, 0, SEEK_CUR); // 파일 위치 지정자 위치를 옮길 필요가 없음에도
            // 파일 위치 지정자 설정을 통해 읽기작업으로 바꿈
        }
    }

    fclose(fp);
}


int test4() {
    FILE *fp = fopen("data.txt", "a");
    // "a"형식이면 append. 파일 맨 끝부분 부터 내용이 쓰여지고
    // 앞 부분은 건들지 않음. 즉, 이전에 들어가있던 내용을 보호함
    // a+형식은 읽기/덧붙이기를 번갈아가면서 할 수 있다.
    // 읽는 작업은 어디든지 가능하지만, 쓰기 작업의 경우 끝부분위치부터 쓸수있다.
    char c;

    if (fp == NULL) {
        printf("fail\n");
        return 0;
    }

    // 아래 내용이 파일 뒤에 덧붙여진다.
    fputs("IS ADDED HAHAHAHA", fp);
    fclose(fp);
}


int test5() {
    // There is some data in this FILE!!!!
    FILE *fp = fopen("data.txt", "r");
    char data[100];

    if (fp == NULL) {
        printf("파일 열기 오류\n");
        return 0;
    }

    // scanf는 stdin 스트림에서만 받을 수 있고, fscanf는 임의의 스트림에서 입력 받기 가능
    while (fscanf(fp, "%s", data) != EOF) {
        // fgets는 \n이 나올 떄까지 하나의 문자열로 보고 받지만
        // fscanf는 띄어쓰기' ' 탭문자 \t \n 등 어느 하나가 나올 때까지 입력 받는다
        // 즉, 파일에서 각 단어들을 하나씩 읽어들이게 된다
        // 물론 읽은 만큼 파일 위치 지정자는 이동하게 됨
        // fscanf가 더이상 새로운 데이터를 입력받을 수 없을 경우 EOF 리턴(끝)
        printf("%s \n", data);
    }

    // fscanf(stdin, "%s", data); == scanf("%s", data);
    // fgets와는 달리 띄어쓰기나 탭 문자들을 모두 인식함

    fclose(fp);
}


int test5() {
    FILE *fp = fopen("data.txt", "r+");
    char data[100];

    if (fp == NULL) {
        printf("error");
        return 0;
    }

    // 모든 "this"를 "that"으로 replace
    while (fscanf(fp, "%s", data) != EOF) { // 파일에서 단어를 입력받음
        if (strcmp(data, "this") == 0) { // 각각의 단어가 "this"와 같은지 비교
            fseek(fp, -(long)strlen("this"), SEEK_CUR); // t를 가리키게 됨
            fputs("that", fp);

            fflush(fp); // 읽기형식으로 다시 바꿔준다.
        }
    }

    fclose(fp);
}