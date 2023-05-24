#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main() {

    stack st = {{1, 3, 7}, 3};

    print(st);
    push(&st, 6);
    print(st);

    int y;
    y = pop(&st);
    printf("%d\n", y);
    print(st);

    printf("%d", is_empty(st));

    return 0;
}
