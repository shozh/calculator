#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include <string.h>

int var = 15;

int get_value(const char *name) {
    if (strcmp(name, "var") == 0) {
        return var;
    }
    return 0;
}

int main() {

    int a = 20;
    int b= 10;

    printf("%d\n", get_value("var"));


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