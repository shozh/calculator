#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

#include <stdbool.h>

typedef int Data;
typedef struct Node {
    Data data;
    struct Node *next;
} Node;

void print_list(Node*);

void push_front(Node**, Data x);

void push_back(Node**, Data x);

bool is_list_empty(Node*);

Node* arr2list(const Data*, int);

void insert(Node**, Data, int);

Data pop_front(Node**);

Data pop_back(Node**);

Data erase(Node**, int);



#endif //CALCULATOR_LIST_H