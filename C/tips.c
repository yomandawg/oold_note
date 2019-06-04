#include <stdio.h>


// 부동 소수점(float, double)은 되도록 사용 말자

// 초 증가 함수
int inc_second(int second) { return (++second) % 60; }
// 나눗셈은 느린 연산이다.
int faster_inc_second(int second) {
    ++second;
    if (second >= 60) return 0;
    return second;
}
// CPU에선 명령 실행 소곧를 향상시키기 위해 파이프라이닝 작업을 수행한다
// 다음에 실행될 명령어를 이전 명령어 실행이 끝나기 전에 미리 실행시키는 것
// 문제는 분기문이 있을 경우 다음에 실행할 명령어가 무엇인지 모른다
// 위의 경우 second >= 60이면 return 0;이고 아니면 return second;인데
// second >= 60이 끝날 때까지 기다리지 않는다
// 이전 추세를 보아 대충 예측한 다음 다음 명령어 실행하게 된다.
// => branch prediction
// 예측이 맞았다면 쭉쭉 진행하지만, 예측이 틀리면 작업한 것을 모두 버리고,
// 원래 수행했어야 할 명령어를 다시 실행한다.
// 페널티가 cycle로 따졌을 때
// 정수 나눗셈 연선(DIV)의 경우 10 cycle이 필요하고,
// 덧셈의 경우 1 cycle에 끝나게 된다.
// (CPU에서 한 가지 작업을 수행하는데 걸리는 시간 cycle)
// 예) 4Ghz면 1초에 40억 cycle

// 따라서 분기 예층 정확도를 50% 이상으로 할 수 있으면 위와 같이 분기문으로
// 바꿔서 하는 것이 효율적으로 최적화했다고 볼 수 있다.
// CPU의 분기 예측기는 꽤나 똑똑해서, 이전 분귀 겨로가에 추세를 바탕으로 예측함
// inc_second의 경우 second >= 60이 참일 일이 없기 때문에 (1/60 확률)
// 분기 예측 확률이 꽤 높을 것

// 2의 멱수, 2, 4, 8, 16, 32 등으로 나눌 땐 굳이 나눗셈을 않고도 간단히 처리 가능
// 쉬프트 연산! => 가장 빠른 연산
// 2의 멱수 == 1 10 100 1000 이진수 표현
// 10 진수로 생각할 때 7865를 100으로 나누면 몫이 78으로 엄청 빨리 계산가능
// 2진수도 마찬가지로 11101010을 1000으로 나눈 몫은 마지막 세자리를 버리기만 하면 됨
// 이 아이디어로 1000으로 나눌 때는 오른쪽으로 3칸 쉬프트하기만 하면 됨

int binary_shift() {
    int i;
    scanf("%d", &i);
    printf("%d", i / 32);
    printf("%d", i >> 5); // 결과 일치
}


// 비트 연산 (OR, AND, XOR 등) 컴퓨터에서 가장 빠르게 실행되는 연산
struct HUMAN {
    int is_Alive;
    int is_Walking;
    int is_Running;
    int is_Jumping;
    int is_Sleeping;
    int is_Eating;
};
// 6가지 정보를 위해 192 비트나 소모하였기 때문에 매우 비효율적!
// 비트 연산으로 해결할 수 있다.

#define ALIVE 0x1      // 2 진수로 1
#define WALKING 0x2    // 2 진수로 10
#define RUNNING 0x4    // 2 진수로 100
#define JUMPING 0x8    // 2 진수로 1000
#define SLEEPING 0x10  // 2 진수로 10000
#define EATING 0x20    // 2 진수로 100000
int main() {
    int my_status = ALIVE | WALKING | EATING; // 각 데이터들이 나타내는
    // 자릿수만 1 나머지는 0

    if (my_status & ALIVE) { // ALIVE면 그 자릿수 1이 됨 true
        printf("I am ALIVE!! \n");
    }
    if (my_status & WALKING) {
        printf("I am WALKING!! \n");
    }
    if (my_status & RUNNING) {
        printf("I am RUNNING!! \n");
    }
    if (my_status & JUMPING) {
        printf("I am JUMPING!! \n");
    }
    if (my_status & SLEEPING) {
        printf("I am SLEEPING!! \n");
    }
    if (my_status & EATING) {
        printf("I am EATING!! \n");
    }
    return 0;
}


int check_odd() {
    int i;
    if (i % 2 == 1) printf("true\n"); // 나눗셈은 매우 느리다!

    if (i % 1) printf("true\n"); // 단순히 맨 마지막 비트가 1인지만 확인하면 됨!
}


int loop() {
    int i, n = 10, sum = 0;
    for (i = 1; i <= n; i++) sum += i;

    sum = (n + 1) * n / 2; // 시간 절약 가능

    int * pstr;
    int does_string_has_a;
    while (*pstr) {
        if (*pstr != 'a') {
            does_string_has_a = 1;
            break; // 끝낼 수 있을 때 끝내라
        }
        pstr++;
    }

    // 1인 비트가 몇개냐
    int one_bit = 0;
    while (n != 0) {
        if (n & 1) {
            one_bit++;
        }
        n >>= 1; // 맨 끝 한개의 비트를 검사하고 오른쪽으로 쉬프트해서 또 다시 검사
    }

    // 한번에 많이해라
    while (n != 0) {
        if (n & 1) one_bit++;
        if (n & 2) one_bit++;
        if (n & 4) one_bit++;
        if (n & 8) one_bit++;
        n >>= 4;
    }

    // 아래의 루프가 더 빠르게 돌아감 일반적으로 0 비교 명령어는
    // CPU에 따로 만들어져있기 때문에 더 빠르게 작동함
    for (i = 0; i < 10; i++) printf("a");
    for (i = 9; i != 0; i--) printf("a");

    
    // 순차적 if문이 매우 복잡하면 쪼개는 것을 binary breakdown이라 하는데
    // 이진 형태로 쪼갠 것. 이럴 경우 i가 1~8까지 어떤 값을 갖더라도
    // 3번의 비교로 찾을 수 있다
    // (컴파일러가 해준다)
    // 순차적인 정수 값 비교엔 switch 문을 사용하는 것이 나음
    switch (i) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
    }

}



// 룩업 테이블(look up table, LUT)를 활용하자
// 특정 데이터에서 다른 데이터로 변환할 때 사용되는 테이블
// 예를 들어 연산이 오래걸리는 함수를(sin1~sin90) 미리 계산값을
// 표로 만들어 찾아서 씀
char* Condition_String2(int condition) {
    if ((unsigned)condition >= 15) {
        return 0;
    }
    char* table[] = {"EQ", "NE", "CS", "CC", "MI", "PL", "VS",
                    "VC", "HI", "LS", "GE", "LT", "GT", "LE"};
    return table[condition];
    // 스위치문보다 훨씬 간결하다
}

// 함수 호출엔 시간이 걸린다! (함수 찾기 작업 등등)()
// 동일한 작업을 위해 함수 반복 호출보단 반복 작업으로 활용

__inline int imax(int a, int b) {
    if (a > b) return a;
    return b;
}
// inline 함수를 이용하면 단순한 작업 처리에 효율적
// 인라인 함수는 사실 함수가 아니고 매크로 함수와 같이 컴파일러가 자동 대입
// 수항 작업이 매우 단순할 때 함수 호출 시간이 비효율적이여서 활용


struct big {
    int arr[1000];
    char str[1000];
};
// 위와 같은 거대한 구조체에서 arr[3]을 얻고싶다면

void modify(struct big arg) {} // 보다
// arg 인자로 구조체 변수의 모든 데이터가 복사되므로 엄청난 시간이 걸림
void modify(struct big *arg) {} // 가 더 효율적
// 위는 구조체 변수의 주소값을 얻어온다
// 단순히 4바이트 주소값 복사만이 일어날 분 복사가 일어나지 않아 효율적
// / 동일하게 인자로 전달된 구조체 변수의 데이터들도 손쉽게 읽어올 수 있다
// arg->arg[3] 같은 방식으로
