// 비교문이 반복되는 경우 switch문
// switch문을 이용하면 case에 따라 CMP 연산(compare 연산: 어셈블리어)이 늘어나는 것이 아니라
// `jump table`의 크기만 커질 뿐, 성능의 영향은 받지 않음
// switch문은 값들의 크기가 그다지 크지 않고, 순차적으로 정렬되어 있을 때 유용

#include <stdio.h>

int main() {
    int input;

    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("1");
            break; // break시 아래의 모든 case들을 무시하고 switch 밖으로
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        default: // else와 같은 역할, 1,2,3 모두 아닐 때
            printf("None");
            break;
    }

    char character;

    scanf("%c", &character);

    switch (character) {
        case 'a': // 컴퓨터는 문자와 숫자를 구분 못함; 모두 숫자로 처리 후 우리에게 보여줄 때만 문자 - 문자 == 정수
            print("a");
            break;
        case 'b':
            print("b");
            break;
        default:
            print("letter");
            break;
    }

    return 0;
}