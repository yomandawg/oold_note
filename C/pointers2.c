// 포인터는 특정한 데이터의 메모리 상의 시작주소값을 보관하는 변수
/*
상수 포인터
const int a = 3; // 데이터의 값이 변화하지 않는다

*/

#include <stdio.h>

void test(); void nameofarr();

int main() {
    int a;
    int b;
    const int* pa = &a; // const int* : 가리키는 int형 변수의 값을 바꾸지 마라

    // *pa = 3; // 오류 - 포인터를 통해 a값을 바꿀 수 없다
    a = 3;
    pa = &b; // 포인터를 통해 값을 바꾸지 않았으니 가능

    printf("%d", a);

    test();

    nameofarr();

    return 0;
}

void temp() {
    int a;
    int b;
    int* const pa = &a;

    *pa = 3;
    // pa = &b; // 오류 pa의 값이 const므로 값이 바뀔 수 없다.
    // pa가 처음 가리키는 것 말고 다른것을 건드릴 수 없다.
}

void temp2() {
    int a;
    int b;
    const int* const pa = &a;

    // *pa = 3; // 오류 - pa가 가리키는 값이 바뀔 수 없다
    // pa = &b; // 오류 - pa의 값이 바뀔 수 없다.

}

void pointer_add() {
    int a;
    int* pa;
    pa = &a;

    printf("%p", pa); // 1244812
    printf("%p", pa+1); // 1244816 => 4차이?!
    // 포인터형이 int*이므로 4칸 차지하므로 형의 크기만큼 4가 더해진다
    // 뺄셈 역시 마찬가지
}

void pointer_pointer() {
    int a;
    int *pa = &a;
    int b;
    int *pb = &b;
    // int *pc = pa + pb; // 포인터끼리의 덧셈은 허용하지 않음 - 의미도 없다
    // 포인터끼리의 뺄셈은 가능하다! WHY?!

}

void pointer_assign() {
    int a;
    int* pa = &a;
    int* pb;

    *pa = 3; // a = 3
    pb = pa; // pb에 pa가 가리키는 주소값
    // pa와 pb의 형이 같아야한다 - 형이 다르면 변환해줘여함

    printf("%d", *pa); // 3
    printf("%d", *pb); // 3
}


void array_and_pointer() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 배열의 각 원소는 메모리 상에 연속되게 놓임
    int i;
    for (i = 0; i < 10; i++) {
        printf("%x\n", &arr[i]); // 요소 주소 - 4씩 증가해서 나온다
        // => 포인터로도 배열의 원소에 쉽게 접근 가능하다!
        // => 포인터에 1을 더하면 그 다음 원소를 가리킨다
        // => 포인터측에서 자동으로 주소값 4를 더해주어 배열접근을 쉽게 만든다!
    }
}

void test() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* parr;
    int i;
    parr = &arr[0];

    for (i = 0; i < 10; i++) {
        printf("arr[%d] : %p ", i, &arr[i]);
        printf("(parr + %d) : %p ", i, (parr + i));

        if (&arr[i] == (parr + i)) {
            // 만일 (parr + i) 가 성공적으로 arr[i] 를 가리킨다면
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
}

void wow() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* parr;

    parr = &arr[0];

    printf("arr[3] = %d, *(parr + 3) = %d \n", arr[3], *(parr + 3)); // 4, 4
}

void nameofarr() {
    int arr[3] = {1, 2, 3};

    printf("%p\n", arr); // 똑같다! 배열이름엔 시작주소값이 있음
    printf("%p\n", &arr[0]); // 배열의 이름은 배열의 시작주소를 가리키는 포인터라고 봐도 됨

    int brr[3] = {4, 5, 6};

    // arr = brr; // 안됨 => 다른 주소값을 가리키게 할 수 없음
    // arr은 포인터 상수 형태로 되어 있다. (int* const)
}

// [] 연산자 - 왼쪽 우선
void bracket() {
    int arr[5] = {1, 2, 3, 4, 5};

    printf("a[3] : %d \n", arr[3]);
    printf("*(a+3) : %d \n", *(arr + 3)); // []연산자가 쓰이면 자동적으로 포인터 형태로 바꿔 처리
    // *(arr + 3) == arr[3]
    
    printf("3[arr]: %d \n", 3 [arr]); // []연산자로 3[arr]을 *(3 + arr)로 바꾼다
    printf("*(3+a) : %d \n", *(arr + 3));

    return 0;
}