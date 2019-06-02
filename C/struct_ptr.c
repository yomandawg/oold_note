#include <stdio.h>

int add_one(int *a);

struct TEST {
    int c;
    int *pointer;
};

int main() {
    struct TEST t;
    struct TEST *pt = &t; // 구조체가 아닌 구조체 포인터
    // 모든 포인터는 4byte로 같은 크기

    // pt는 t의 주소값을 갖고 있다(pt는 t를 가리킨다)
    (*pt).c = 1; // same
    pt->c = 1; // 편리한 연산자


    int i = 0;
    t.pointer = &i; // t의 멤버 pointer이 i를 가리키게
    *t.pointer = 3; // t의 멤버 pointer이 가리키는 변수가 3
    // .가 *보다 우선순위가 높으므로 먼저 해석됨

    *pt->pointer = 4;
    // ->가 *보다 우선순위가 높으므로 먼저 해석됨

    printf("t.c : %d \n", t.c);
}

int check() {
    struct TEST t;
    struct TEST *pt = &t;

    pt->c = 0; // pt가 가리키는 구조체 변수의 c멤버를 0으로
    
    add_one(&t.c); // t구조체 변수 멤버 c의 주소값을 인자로
    add_one(&pt->c); // pt가 가리키는 구조체의 멤버 c의 주소값을 인자로

    return 0;
}

int add_one(int *a) {
    *a += 1;
    return 0;
}

struct TEMP {
    int i;
    char c;
};

int struct_assign() {
    struct TEMP st, st2;

    st.i = 1;
    st.c = 'c';
    st2 = st; // st를 st2에 대입함
    // st2의 멤버들의 값은 st와 동일해진다

    return 0;
}

struct TEST2 {
    int i;
    char str[20];
};


char copy_str(char *dest, char *src);

int test2() {
    struct TEST2 a, b;

    b.i = 3;
    copy_str(b.str, "hello, world"); // 멤버초기화

    a = b;

    return 0;
}

char copy_str(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return 1;
}


struct TEST2 {
    int age;
    int gender;
    char name[20];
};

// 구조체는 주소값으로 받아와야함
int set_human(struct TEST2 *a, int age, int gender, const char *name) {
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);
    // name 배열의 주소값과, 복사하려는 문자열의 주소값이 필요
    return 0;
}
// a는 구조체 변수가 아니다! human 구조체 변수가 메모리 상에 위치한 곳의
// 시작점의 주소값을 보관하고 있는 것

int struct_instance() {
    struct TEST2 human; // 구조체 변수 값을 초기화 하고 써야해
    set_human(&human, 10, 1, "Lee"); // 주소 전달해야해, 배열과 달라
    return 0;
}