/*
배열은 포인터와 밀접한 연관이 있다

1차원 배열의 이름은 첫 번째 원소를 가리킨다
int arr[3]; 이라는 배열이 있다면 arr == &arr[0]
그런데, arr[0]이 int형이므로 arr은 int*형이다
=> int형을 가리키는 포인터는 int*이니까 1차원 배열의 이름은 첫번째 원소를 가리킨다.
*/

#include <stdio.h>

int doublepointer(); int array2(); int why();

int main() {
    int arr[3] = {1, 2, 3};
    int *parr;

    parr = arr;
    // parr = &arr[0]; 동일하다
    // arr에 저장되어 있는 값을 parr 에 대입
    // arr은 int를 가리키는 포인터, arr에 저장된 값, 즉 배열의 첫 번째 주소를 parr에 대입


    printf("arr[1] : %d \n", arr[1]);
    printf("parr[1] : %d \n", parr[1]);

    doublepointer();
    array2();
    why();

    return 0;
}


int useful() {
    int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};

    int* parr = arr; // 굳이 따로 선언하는 이유는 arr을 증가시켜서 접근하면 오류
    // 배열의 이름은 const이므로 연산할 수 없다
    // *arr = 10;과 같이 arr[0]의 값은 바꿀 수 있지만, arr++와 같은 연산은 안됨
    // 배열을 아무도 가리키지 않는 메모리 상의 미아가 됨을 막으려고 한 것
    int sum = 0;

    while (parr - arr <= 9) {
        sum += (*parr);
        parr++; // 포인터 연산 1 증가 == parr가 가리키는 타입의 크기만큼이 증가
        // int형 포인터이므로 4가 더해져서, 배열의 그 다음 원소를 가리킬 수 있게 된다.
    }

    printf("평균 점수: %d \n", sum / 10);
    return 0;
}


int doublepointer() {
    int a;
    int *pa;
    int **ppa; // int*를 가리키는 포인터

    pa = &a;
    ppa = &pa;

    a = 3;

    printf("a : %d // *pa : %d // **ppa : %d \n", a, *pa, **ppa);
    // pa가 a를 가리키고 있으므로 *pa를 하면 a를 지칭하는 것이 되어 a의 값이 출력
    // **ppa는 *(*ppa)가 되는데, *ppa는 pa를 지칭하기 때문에 *pa가 돼서, 결국 a를 지칭하게 되는 것
    printf("&a : %d // pa : %d // *ppa : %d \n", &a, pa, *ppa); // pa가 a를 가리키고 있으므로 pa는 a의 주소값이 들어간다
    // &a와 pa는 같다, ppa는 pa를 가리키고 있으므로 *ppa를 하면 pa를 지칭하게 되는 것
    printf("&pa : %d // ppa : %d \n", &pa, ppa); // ppa에는 pa의 주소값이 들어가게 된다

    return 0;
}


int array2() {
    int arr[2][3];

    printf("arr[0] : %p \n", arr[0]); // arr[0]에 저장되어 있는 값 == arr[0][0]의 주소값
    printf("&arr[0][0] : %p, \n", &arr[0][0]);
    // arr[0]은 arr[0][0]을 가리키는 포인터

    printf("arr[1] : %p \n", arr[1]); // arr[1]에 저장되어 있는 값 == arr[1][0]의 주소값
    printf("&arr[1][0] : &p \n", &arr[1][0]);
    // arr[1]은 arr[1][0]을 가리키는 포인터
    // arr[0][0]의 형이 int이므로 arr[0]은 int*형

    printf("&arr[0] : %p \n", &arr[0]);
    printf("arr : %p \n", &arr);
    // same as printf("arr : %p \n", &arr);
    // arr[0]의 주소값 == arr값

    return 0;
}

// 실제로 1차원 int배열에서도 이름이 배열의 첫 번째 원소를 가리킨다
// 2차원 배열도 arr이 arr[0]을 가리키고 있으므로 동일
// arr[0]이 int*형이므로 arr은 int**? 아니다!
// WHY?!
int why() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int **parr;
    // 배열이 int**형이 될 수 없다?!

    // parr = arr;

    // printf("arr[1][1] : %d \n", arr[1][1]);
    // printf("parr[1][1] : %d \n", parr[1][1]);

    printf("arr : %p, arr + 1 : %p \n", arr, arr + 1);
    // b 값은 3이고 int는 4byte이므로 3*4=12만큼 증가

    return 0;
}
/*
오류가 난다.(int**의 간접 참조 수준이 int (*)[3]과 다릅니다.)
arr[10] = 2;와 같이 허가되지 않은 공간에 접근하면 오류가 발생한다
위 예제도 parr[1][1]에서 이상한 메모리 공간의 값에 접근하기 때문에 오류
일차원 배열에서 배열의 형과 시작주소를 안다고 칠 때, n번째 원소를 시작 주소값ㅅ을 알아내는 공식은?
배열의 형을 int로 가정하고 시작 주소를 x라고 할 때, x+4*(n-1) 로 접근(int 4byte)
2차원 배열에선 int arr[a][b]; 라고 가정할 때,
메모리는 선형(1차원)이므로 순차적으로 메모리에 배열된다
그렇다면 위 배열의 시작주소를 x라 하고, int 형 배열이고 arr[c][d]라는 원소에 접근한다고 치면,
원소의 주소값은?
일단 원소는 (c+1)행의 (d+1)열에 위치
그러면 먼저 (c+1)행의 시작 주소는 = x+c*b*4
그리고 이 원소가 d+1번째에 있다면 (c+1)행 시작주소 + d*4 = (x+4bc+4d)
주목할 점은 식에 b가 들어가는데 arr[a][b]를 정의했을 때의 b가 원소의 주소값을 계산하기 위해 필요
이전에 int**로 배열의 이름을 나타낼 수 있다고 생각하였는데 이러면 선언된 parr으로
parr[1][1] 원소를 참조하려고 하면 컴퓨터는 b값을 알 수 없기 떄문에 연산을 할 수 없다
따라서 이차원 배열을 가리키는 포인터는 반드시 b값에 대한 정보를 포함해야 함
1. 가리키는 것에 대한 정보 (예를 들어, int*이면 int를 가리킨다 char**이면 char*을 가리킨다 등)
2. 1증가시 커지는 크기(2차원 배열에서는 b*(형의 크기)를 의미한다)
*/

int arraypointer() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*parr)[3]; // 괄호 필요
    // 배열의 형(int) 를 통해서 가리키는 것에 대한 정보를 알 수 있다 (원소의 크기)
    // 2차원 배열의 열 개수를 통해서 1증가시 커지는 크기도 알게 된다
    // int형 이차원 배열을 가리키는데, 그 배열의 열의 개수가 3개 라는 소리
    // (int*를 가리키는데 1 증가시 3이 커진다)

    parr = arr; // parr이 arr을 가리키게 한다

    printf("parr[1][2] : %d, arr[1][2] : %d \n", parr[1][2]; arr[1][2]);
    // 6, 6

    return 0;
}


int check() {
    int arr[2][3] = {{1, 2, 3,}, {4, 5, 6}};
    int brr[10][3];
    int crr[2][5];
     
    int (*parr)[3];

    parr = arr;
    parr = brr;
    parr = crr; // 오류

    // 2차원 배열에서 원소의 주소값을 계산하는 식: x+4bc+4d
    // a의 값이 필요 없다!: b값만 알고 있다면 a와 무고나하게 원소에 접근 가능
    // parr이 arr[2][3]과 brr[10][3]을 가리킬 수 있다

    // 왜냐하면 b값, 즉 열의 개수가 동일한 이차원 배열이기 때문
    // carr은 arr과 b의 값(3, 5)가 다르기 때문에 parr에 crr을 대입하면 오류
}


int ptrarr() {
    int *arr[3]; // 포인터 배열
    int a = 1, b = 2, c = 3;
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    printf("a : %d, *arr[0] : %d \n", a, *arr[0]);
    printf("b : %d, *arr[1] : %d \n", b, *arr[1]);
    printf("b : %d, *arr[2] : %d \n", c, *arr[2]);

    printf("&a : %d, arr[0] : %d \n", &a, arr[0]);
    // 배열의 형을 int*로도 할 수 있다
    // 다시말해, 배열의 각각의 원소는 'int를 가리키는 포인터' 형으로 선언된 것

    // 각각의 원소는 각각 int형 변수 a, b, c를 가리키게 된다
    return 0;
}