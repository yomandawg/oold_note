// 잡다한 키워드들

#include <stdio.h>

struct HUMAN {
    int age, height, weight, gender;
};

typedef int CAL_TYPE; // CAL_TYPE이 int와 같다고 정의
// 기존에 모든 변수 타입을 다 수정해야 할 때? CAL_TYPE 만 바꾸면 된다!

typedef struct HUMAN Human; // struct HUMAN 이라는 타입에 Human 이라는 이름을 붙인 것

typedef int (*Padd)(int, int);
typedef int Arrays[10];


typedef struct SENSOR {
    int sensor_flag;
    int data;
} SENSOR;


int print_status(Human human);

int add(int a, int b) { return a + b };

int main() {
    Human Adam = {31, 182, 75, 0}; // Human 이라고만 써도 됨
    print_status(Adam);

    
    CAL_TYPE input;
    CAL_TYPE a, b;

    scanf("%d %d", &input, &a);
    if (input == 1) printf("%d", a);


    Arrays arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // int arr[10]; 과 동일
    Padd ptr = add; // 복잡한 함수 포인터 명령을 Padd라고 명명
    // int (*ptr)(int, int) = add; 와 동일
    printf("%d", arr[3]);
    printf("%d", ptr(3, 5));


    SENSOR *sensor;
    while(!(sensor->sensor_flag)) {}
    printf("%d\n", sensor->data);
    // while문 탈출하지 못하게 되어 무한루프!
    // 1. 컴파일러 최적화 옵션 빼기
    //      - gcc에선 단순히 최적화 옵션을 안주면 된다.
    //      - visual studio에선 프로젝트 속성의 C/C++ -> 최적화 사용 안함 선택
    // 최적화 안하면 너무 손실이 크다! - 다른 코드들도 최적화 하지 않겠다는 의미
    // 2. volatile

    volatile SENSOR *sensor_v; // 변덕스러운 volatile => sensor_v에 대한 값이 변할 수 있기 때문에
    // 최적화 작업들을 수행하지 말라
    // 값이 감지되지 않는 동안 계속 무한 루프를 돈다
    while (!(sensor_v->sensor_flag))
    printf("%d\n", sensor_v->data);
}


int volatile_ex() {
    int i = 0;
    while (i < 10) i++;
    printf("%d", i); // 10
    // 컴파일러는 위 코드를 최적화하여 while반복문을 없애버리고 i에 그냥 10을 할당한다.

    volatile int j = 0; // volatile로 선언하여 항상 메모리에 접근하도록 만듦
    while (j < 10) j++;
    printf("%d", j); // 10
    // 항상 j의 메모리에 접근해야 하므로 컴파일러는 반복문을 없애지 않음
}


int print_status(Human human) {
    if (human.gender == 0) printf("Male\n");
    return 0;
}