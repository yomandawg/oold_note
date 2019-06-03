#include <stdio.h>
#include "human.h"
#include "str.h"

struct Human create_human(char *name, int age, int gender) {
    struct Human human;
    human.age = age;
    human.gender = gender;
    copy_str(human.name, name);
    return human;
}

int print_human(struct Human *human) {
    printf("%s\n", human->name);
    if (human->gender == MALE) printf("MALE\n");
    else if (human->gender == FEMALE) printf("FEMALE\n");
    return 0;
}