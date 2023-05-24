#ifndef CALCULATOR_LIST_H
#define CALCULATOR_LIST_H

typedef int Data;
typedef struct Node {
    Data data;
    struct Node *next;
} Node;

void print_list(Node*);
void push_front(Node**, Data x);
//void insert(Node*, int i);
//void erase(Node*, int i);



#endif //CALCULATOR_LIST_H
