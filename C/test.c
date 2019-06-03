#include <stdio.h>
#include "human.h"

int main() {
    struct Human Lee = create_human("Lee", 40, MALE);
    print_human(&Lee);
    return 0;
}