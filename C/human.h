/*
헤더 파일에도 보통의 C코드를 집어넣을 수 있지만 권장은 하지 않는다
*/

enum { MALE, FEMALE };

struct Human {
    char name[20];
    int age;
    int gender;
};

struct Human create_human(char *name, int age, int gender);
int print_human(struct Human *human);