#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H

#include <stdbool.h>

typedef struct {
    int a[1000];
    int n;
} stack;

void print(stack);
void push(stack*, int);
int pop(stack*);
bool is_empty(stack);

#endif
