#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void print_list(Node* list) {
    for (Node* p = list; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

void push_front(Node** plist, Data x) {
    Node *new = malloc(sizeof(Node));
    new->data = x;
    new->next = *plist;
    *plist = new;
}
