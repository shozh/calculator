#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

#include <stdbool.h>

#define put_space(x) _Generic((x), \
    int: printf("%d ", x), \
    float: printf("%.3f ", x), \
    double: printf("%.3lf ", x), \
    char*: printf("%s ", x), \
    const char*: printf("%s ", x), \
    char: printf("%c ", x) \
)

typedef int Data;
typedef struct Node {
    Data data;
    struct Node *next;
} Node;

void print_list(Node*);

void print_list1(Node*);

void push_front(Node**, Data x);

void push_back(Node**, Data x);

bool is_list_empty(Node*);

Node* arr2list(const Data*, int);

void insert(Node**, Data, int);

Data pop_front(Node**);

Data pop_back(Node**);

Data erase(Node**, int);



#endif //CALCULATOR_LIST_H