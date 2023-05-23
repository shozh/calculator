#include "stack.h"
#include <stdio.h>

void print(stack *st) {
    for (int i = 0; i < st->n; i++)
        printf("%d ", st->a[i]);
    printf("\n");
}


void push(stack *st, int x);
int pop(stack *st);


int is_empty(stack *st);

