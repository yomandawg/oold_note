/*
포인터는 특정한 변수의 메모리 상의 주소값을 저장하는 변수로, int형 변수의 주소값을 저장하면
int*, char 이면 char* 등등
*연산자로 자신이 가리키는 변수를 지칭할 수 있으며
& 연산자를 이용하여 특정한 변수의 주소값을 알아낼 수 있다.
*/

#include <stdio.h>

int swap(int *a, int *b); // 함수의 원형(prototype) - 함수의 정의 부분을 써준 것
// 컴파일러에 소스코드에 이러한 함수가 정의되어 있다는 것을 알림
// 프로그램엔 반영되지 않은 정보 - 실수않도록 도와준다
// 하지만 원형 내의 인자정보를 바꾸면 오류
// 컴파일러에게 인자정보를 알림으로써 정확한 정보 전달
// main함수 위에 함수를 정의하면 상관없지만 그것은 관례가 아님
int add_number(int *parr); int isdigit(char c);

int change_val(int *pi) { // 포인터로 인자를 받는다 - 포인터를 통해 간접적으로 접근
    printf("----- chage_val 함수 안에서 -----\n");
    printf("pi 의 값 : %d \n", pi);
    printf("pi 가 가리키는 것의 값 : %d \n", *pi);

    *pi = 3; // pi가 가리키는 값에 3을 넣는다

    printf("----- change_val 함수 끝~~ -----\n");
    return 0;
}
int main() {
    int i = 0;

    printf("i 변수의 주소값 : %d \n", &i);
    printf("호출 이전 i 의 값 : %d \n", i); // 0
    change_val(&i); // i의 주소값을 인자로 전달한다
    printf("호출 이후 i 의 값 : %d \n", i); // 3

    int arr[3];
    int j;
    for (j = 0; j < 3; j++) {
        scanf("%d", &arr[j]);
    }

    char input;
    scanf("%c", &input);
    if (isdigit(input)) {
        printf("YES");
    } else {
        printf("NO");
    }

    add_number(arr); // arr은 배열의 시작 주소값, 즉 arr = &arr[0] 이므로 parr에는 arr의 시작 주소
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    return 0;
}

// 두 변수의 값을 교환
int swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    return 0;
} // doesn't work w/o ptrs

int trueswap(int *a, int *b) { // 주소값을 전달하여 간접적으로 접근
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
// 어떤 함수가 특정 타입의 변수/배열의 값을 바꾸려면 함수의 인자는 반드시 그 타입을 가리키는 포인터를 이용


// 배열 인자로 받기
int add_number(int *parr) { // 특정 타입의 값을 변경하려면 반드시 그 타입을 가리키는 포인터를 인자로
    int i;
    for (i = 0; i < 3; i++) {
        parr[i]++; // 배열의 각 원소들의 크기를 모두 1씩 증가
    }
    return 0;
}

int max_number(int *parr) { // 가장 큰 수를 뽑는 것
    int i;
    int max = parr[0];

    for (i = 1; i < 10; i++) {
        if (parr[i] > max) {
            max = parr[i];
        }
    }

    return max;
}


int isdigit(char c) {
    if (48 <= c && c <= 57) { // 숫자 ASCII코드 48~57
        return 1;
    } else
    {
        return 0;
    }
}