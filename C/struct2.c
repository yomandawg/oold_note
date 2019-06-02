#include <stdio.h>

struct employee {
    int age;
    int salary;
};

struct company {
    struct employee data; // 구조체 안의 구조체
    // 구조체는 사용자가 정의한 type이므로 가능
    char name[10];
};

int main() {
    struct company Kim;

    Kim.data.age = 31; // 구조체의 구조체 member 접근
    Kim.data.salary = 3000000;

    return 0;
}


struct AA {
    int i;
};

struct AA function(int j) { // struct AA형을 리턴하는 함수
    struct AA A; // 리턴하는 것 역시 struct AA형이여야함
    A.i = j; // 구조체 초기화
    return A;
}

int returnstruct() {
    struct AA a;
    a = function(10);
    return 0;
}




struct obj {
    char name[20];
    int x, y;
} Ball;
// struct obj Ball; 과 같은 것

int print_obj_status(struct obj OBJ) {
    printf("%s\n", OBJ.name);
    printf("%d %d\n", OBJ.x, OBJ.y);
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

int newer_struct_define() {
    Ball.x = 3;
    Ball.y = 4;
    copy_str(Ball.name, "RED");
    print_obj_status(Ball);
    return 0;
}



struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

int print_status(struct HUMAN human) {
    if (human.gender == 0) {
        printf("MALE \n");
    } else {
        printf("FEMALE \n");
    }

    printf("%d %d %d \n", human.age, human.height, human.weight);

    if (human.gender == 0 && human.height >= 180) printf("Winner\n");
    else printf("Loser\n");

    return 0;
}

int easier() {
    // 순차적으로 멤버에 대입된다.
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    print_status(Adam);
    print_status(Eve);
}

// 구조체 선언에서 초기화 가능
struct YOMAN {
    char name[20];
    int yo;
    int man;
} Dawg = {"abc", 0, 1}, Dawg2 = {"def", 1, 0};