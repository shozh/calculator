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

bool is_list_empty(Node* list) {
    return (list == NULL);
}

void push_back(Node** plist, Data x) {
    Node* new = malloc(sizeof(Node));
    new->data = x;
    new->next = NULL;

    if (is_list_empty(*plist)) {
        *plist = new;
        return;
    }

    Node* t = *plist;
    for (; t->next != NULL; t = t->next);
    t->next = new;
}

Node* arr2list(const Data* b, int n) {
    Node* new = malloc(n *sizeof(Node));

    new[0].data = b[0];
    for (int i = 1; i < n; i++) {
        new[i-1].next = &new[i];
        new[i].data = b[i];
    }
    new[n-1].next = NULL;
    return new;
}

void insert(Node** plist, Data x, int i) {
    if (i == 0)
        push_front(plist, x);
    else {
        Node* new = malloc(sizeof(Node));
        new->data = x;

        Node* list = *plist;
        for (int j = 0; j < i - 1; j++) {
            list = list->next;
            if (list == NULL)
                return;
        }


        new->next = list->next;
        list->next = new;
    }
}

