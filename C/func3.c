// 어떤 함수가 특정한 타입의 변수/배열의 값을 바꾸려면 함수의 인자는 반드시 타입을 가리키는 포인터 형을 이용


#include <stdio.h>

int pswap(int **pa, int **pb); int add1_element(int (*arr)[2], int row);

int main() {
    int a, b;
    int *pa, *pb;

    pa = &a;
    pa = &b;

    printf("pa 가 가리키는 변수의 주소값 : %x \n", pa);
    printf("pa 의 주소값 : %x \n \n", &pa);
    printf("pb 가 가리키는 변수의 주소값 : %x \n", pb);
    printf("pb 의 주소값 : %x \n", &pb);

    printf(" ------------- 호출 -------------- \n");
    pswap(&pa, &pb);
    printf(" ------------- 호출끝 -------------- \n");

    printf("pa 가 가리키는 변수의 주소값 : %x \n", pa);
    printf("pa 의 주소값 : %x \n \n", &pa);
    printf("pb 가 가리키는 변수의 주소값 : %x \n", pb);
    printf("pb 의 주소값 : %x \n", &pb);



    int arr[3][2];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    add1_element(arr, 3);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j ++) {
            printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
        }
    }
    
    return 0;
}

int add1_element(int (*arr)[2], int row) { // 하나는 열의 개수가 2인 이차원 배열, 하나는 행의 수
    // addl_element(int arr[][2], int row) 로 인자 정의해도 돼(포인터 개념이므로)
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 2; j++) {
            arr[i][j]++;
        }
    }
    return 0;
}


int pswap(int **ppa, int **ppb) {
    // 특정한 타입의 변수의 값을 바꾸려면, 특정한 타입을 가리키는 포인터로 인자를 취해야 한다
    // 특정한 타입은 int*타입이므로 int*타입을 가리키는 포인터는 int**
    int *temp = *ppa;

    printf("ppa 가 가리키는 변수의 주소값 : %x \n", ppa);
    printf("ppb 가 가리키는 변수의 주소값 : %x \n", ppb);

    *ppa = *ppb;
    *ppb = temp;

    return 0;
}


int read_val(const int val) {
    // val = 5; // 허용되지 않는다
    // const int로 선언했기 때문에, 인자로 전달된 값으로 초기화되고 바뀌지 않는다.
    return 0;
}