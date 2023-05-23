#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H

typedef struct {
    int a[1000];
    int n;
} stack;

void print(stack*);
void push(stack*, int);
int pop(stack*);
int is_empty(stack*);

#endif
