/* Enum
각 데이터에 수를 대응시키는 경우가 많이 생긴다
문제는 대응하는 상수 설정을 위해 메모리가 낭비된다.
Enum(열거형)을 도입해서 해결 가능
*/

#include <stdio.h>
enum { RED, BLUE, WHITE, BLACK };
// 각 원소에 0부터 차례로 정수값을 매겨주게 된다.
// 즉 RED = 0; BLUE = 1; ... BLACK = 3;
// if (palette == 0) 은 if (palette == RED)와 같다
enum { THREE=3, FOUR, FIVE };
// THREE = 3 ... FIVE = 5로 정수값 매긴다
// 열거형은 언제나 정수값이다

int main() {
    int palette = RED;
    switch (palette) {
        case RED: // case 0; 과 같다
            printf("RED");
            break;
        case BLUE:
            printf("BLUE");
            break;
        case WHITE:
            printf("WHITE");
            break;
        case BLACK:
            printf("BLACK");
            break;
    }
}