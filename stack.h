#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H

#include <stdbool.h>

typedef float data_s;

typedef struct {
    data_s a[1000];
    int n;
} stack;

void print(stack);

void push(stack*, data_s);

void init(stack*);

data_s pop(stack*);

bool is_empty(stack);

data_s top(stack);

#endif
