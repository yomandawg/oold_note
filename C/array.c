#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 특정한 형(type) 변수들의 집합

    printf("%d", arr[2]);

    const int a = 3; //상수
    // 처음에 한 번 저장된 값은 '절대로' 변하지 않는다

    int b = 3;
    const int c = b;
    // char d[b]; still not possible

    int _brr[3]; // 초기화 없이는 쓰레기값
    printf("d", _brr[0]);

    int _arr[3] = {1}; // 단수 초기화하면 0으로 초기화
    _arr[1] = 2;
    printf("%d %d %d", _arr[0], _arr[1], _arr[2]); // 초기화되지 않은 값은 0

    return 0;
}


// 메모리에서 한 '방'은 4byte
// 다른 변수들의 값들을 침범하는 것을 막음

// 소수를 찾는 프로그램
int prime_number() {
    int guess = 5;
    int prime[1000];
    // int prime[guess]; impossible! 변수를 통해 배열 사이즈 정의 불가
    // 처음에 컴파일러가 배열을 처리할 때 메모리 상에서 공간을 잡아야함

    int index = 1;
    int i;
    int ok;
    prime[0] = 2;
    prime[1] = 3;
    for (;;) {
        ok = 0;
        for (i = 0; i <= index; i++) {
            if (guess % prime[i] != 0) {
                ok++;
            } else {
                break;
            }
        }
        if (ok == (index + 1)) {
            index++;
            prime[index] = guess;
            printf("%d", prime[index]);
            if (index == 999) break;
        }
        guess += 2;
    }
    return 0;
}