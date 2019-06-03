#include <stdio.h>

int read_char(void *p, int byte);

void main() { // void 형 리턴 => 리턴값이 없다(아무 형도 아님)
    // void a; // void형 변수: 메모리 상의 위치가 결정되지 않았다: 오류
    // a = 3; 지정할 수 없다
    void *a; // 포인터는 무조건 메모리 상의 4byte를 차지하기 때문에 void형 가능
    // void형 변수가 존재할 수 없기 때문에 거꾸로 생각하면 어떤 형태의 포인터값도 담을 수 있게 됨

    double b = 123.3;
    a = &b; // a는 순전히 주소값 보관의 역할만 함

    // printf("%ls", *a); // 오류: void포인터라 메모리상에서 얼마만큼 읽어들여야 할 지 모른다.
    printf("%lf", *(double *)a); // 단순히 주소값만 담고 있는 a에게 double 가리키라는 것을 알려야함

    
    int arr[1] = {0x12345678};
    printf("%x \n", arr[0]);
    read_char(arr, 4);
}

// 리턴할 필요가 없는 함수: void형 함수
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// void형 포인터는 어떤 타입의 포인터 주소값을 담을 수 있기 때문에 자주 활용
// 어떤 특정 주소값으로부터 1바이트씩 읽어오는 함수
// => 2개의 인자(주소값을 가리키는 포인터, 얼마나 읽을지 int형 변수)
// 근데 인자로 전달될 특정한 주소값 가리키는 포인터의 타입이 제각각이라면? (int* double* ...)
// void형 포인터 사용해서 type알려주기
int read_char(void *p, int byte) {
    do {
        printf("%s \n", *(char *)p); // p가 가리키는 주소값에 위치한 데이터 1바이트씩 16진수로 출력
        // 리틀엔디안이므로 78(큰 갚의 주소가 앞쪽에) 56 34 21 순으로 출력
        byte--;
    } while (((char *)p)++ && byte); // char *로 ++하면 p주소에 char(1) 만큼 늘어남
    // 우선순위에 의해 포인터 지시 후 ++함
    // byte의 값이 0이 되거나
    // (char *)p의 값이 0(NULL)일 때, 종료
    return 0;
}