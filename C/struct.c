/*
책의 정보를 수정하기 위해 함수에 인자로 전달할 때 상당히 불편!
사람의 정보를 수정하기 위해 함수를 호출할 떄마다 많은 정보들을 인자로 전달하면 비효율적이다
배열같은 경우 한번에 처리해서 변수이름만 전달해서 쉽게 처리 가능
배열과 같은 논리가 정보에서도 적용될 수 있을까?
=> 한 사람의 정보를 한 개의 배열에 모두 저장할 수 있나? => 구조체
*/

#include <stdio.h>

char copy_str(char *dest, const char *src);

struct Human { // 구조체: 각 원소의 타입이 제각각인 배열
    // 구조체의 원소(멤버:member)들
    int age; // 모든 원소의 타입을 명시해 주어야 한다.
    int height;
    int weight;
};

struct Books {
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed;
    //  int borrowed = 0; // 오류: 구조체에서 변수를 초기화 할 수 없다
};

struct test {
    int a, b;
};

int main() {
    struct Human Psi; // 구조체 변수 정의 - type(형) 정의 구조체
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    Harry_Potter.borrowed = 0;

    Psi.age = 99; // 구조체 멤버 접근(마치 배열에서 arr[3]같은 것)
    Psi.height = 185; // .를 이용하고 멤버가 무엇인지 명시
    Psi.weight = 80;

    printf("age : %d\n", Psi.age);



    struct Books book_list[3]; // struct Book가 하나의 type으로 생각하면
    // / book_list배열에 struct Books형 변수 3개가 만들어진다.
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
        book_list[i].borrowed = 0;
    }

    for (i = 0; i < 3; i++) {
        printf("%s\n", book_list[i].name);
        if (book_list[i].borrowed == 0) {
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }



    // 구조체 포인터
    struct test st;
    struct test *ptr; // struct test형을 가리키는 포인터 ptr
    // ptr은 절대로 구조체가 아니다! 다른 모든 포인터처럼 4(8)바이트 공간을
    // 차지하는 것(그냥 포인터! 시작지점!)

    ptr = &st; // ptr에 st의 주소값을 넣는다
    // 보통 배열에선 int *ptr = arr; 인데 여기는 &st이네? 왜일까!
    // 구조체 변수의 이름은 역할이 살짝 다르다.
    // (배열)이라고 부르지 않고 (구조체)라 부르므로 그냥 메모리 주소값을 얻는다.

    (*ptr).a = 1; // (*ptr) == st
    (*ptr).b = 2; // *ptr.b하면 오류 왜냐하면 연산자 우선순위 때문에!
    // .이 *보다 우선순위가 높다.
    // *ptr.a를 사용하면 ptr.a실행한 후 *를한다.
    // ptr은 단순히 포인터에 불과하므로 .연산자를 할 수 없다.
    
    ptr->a = 1; // (*ptr).a는 귀찮으므로 ->기호로 대체 == 정확히 똑같은 말
    ptr->b = 2;

    printf("st's a member: %d\n", st.a);
    



    return 0;
}


int copy_str(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return 1;
}