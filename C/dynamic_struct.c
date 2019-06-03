#include <stdio.h>
#include <stdlib.h>


// 구조체 동적 할당

struct Something {
    int a, b;
};

int main() {
    struct Something *arr; // 1차원 구조체 배열을 가리키기 위한 arr 선언
    // int형 배열을 위해 int *arr;과 같음
    int size, i;

    scanf("%d", &size);

    arr = (struct Something *)malloc(sizeof(struct Something) * size);
    // sizeof를 안쓰고 구조체 메모리값을 계산하면 오류가 나올 수 있다.
    // 구조체의 크기가 10바이트일 경우 컴퓨터가 더블워드 경계(double word boundary)로 속도 향상
    // 시킬 수 있는데 이 때 구조체의 크기는 12바이트가 될 수 있다. => 크기 추정하지 말자

    for (i = 0; i < size; i++) {
        printf("arr[%d].a : ", i);
        scanf("%d", &arr[i].a);
        printf("arr[%d].b : ", i);
        scanf("%d", &arr[i].b);
    }

    for (i = 0; i < size; i++) printf("arr[%d].a, : %d , arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);

    free(arr);

    return 0;
}

