#include <stdio.h>

#include "lib.c"
#include "stack.c"


int main() {
    printf("Hello, World!\n");

    stack st = {{1, 3, 7}, 3};

    print(&st);

    return 0;
}
