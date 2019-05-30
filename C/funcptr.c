/*
함수를 가리키는 포인터(함수가 메모리 상에 있다)
프로그램의 코드 자체가 메모리 상에 존재한다.

변수를 가르키는 포인터처럼 함수 포인터는 메모리 상에 올라간 함수의 시작 주소를 가리키는 역할을 한다
함수 포인터가 함수를 가리키기 위해선는 그 함수의 시작 값을 알아야 함.
*/

#include <stdio.h>

int max(int a, int b); int donothing(int c, int k);

int main() {
    int a, b;
    int (*pfunc)(int, int); // 함수 포인터 pmax 정의 - 인자가 없다면 괄호를 비우면 된다
    // int (*a)();
    pfunc = max; // pmax가 max를 가리킴 - max 함수의 시작 주소값을 pmax에 대입

    scanf("%d %d", &a, &b);
    printf("max(a,b) : %d \n", max(a, b));
    printf("pmax(a,b) : %d \n", pfunc(a, b));

    pfunc = donothing;

    printf("donothing(1,1) : %d \n", donothing(1, 1));
    printf("pfunc(1, 1) : %d \n", pfunc(1, 1));

    return 0;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;

    return 0;
}

int donothing(int c, int k) { return 1; }
// 인자의 변수도 다르고 하는 일도 다르지만 return값이 같고, 두 개의 인자 모두 int이므로 가리킬 수 있다

/*
int increase(int (*arr)[3], int row) // 첫 번째 인자의 형읜 int (*)[3] - 이름 빼고 생각
int (*pfunc)(int (*)[3], int)  함수 포인터 원형은 이렇게 생겼다
*/