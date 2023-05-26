#include "list.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void print_list(Node* list) {
    for (Node* p = list; p != NULL; p = p->next)
        put_space(p->data);
    printf("\n");
}

void print_list1(Node* list) {
    for (Node* p = list; p != NULL; p = p->next) {
        switch (p->data) {
            case 5000:
                put_space("+");
                break;
            case 5001:
                put_space("-");
                break;
            case 5002:
                put_space("*");
                break;
            case 5003:
                put_space("/");
                break;
            default:
                put_space(p->data);
        }
    }


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

//Node* arr2list(const Data* b, int n) {
//    Node* new = malloc(n *sizeof(Node));
//
//    new[0].data = b[0];
//    for (int i = 1; i < n; i++) {
//        new[i-1].next = &new[i];
//        new[i].data = b[i];
//    }
//    new[n-1].next = NULL;
//    return new;
//}

Node* arr2list(const Data* b, int n) {
    Node* head = NULL;
    Node* cur = NULL;
    Node* prev = NULL;

    for (int i = 0; i < n; i++) {
        cur = (Node*)malloc(sizeof(Node));
        cur->data = b[i];
        cur->next = NULL;

        if (prev == NULL) {
            head = cur;
        } else {
            prev->next = cur;
        }
        prev = cur;
    }

    return head;
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

Data pop_front(Node** plist) {
    if (is_list_empty(*plist))
        return 404;

    Node* list = *plist;
    Data ret = list->data;
    *plist = list->next;
    free(list);
    return ret;
}

Data pop_back(Node** plist) {
    if (is_list_empty(*plist))
        return 404;

    Node* list = *plist;
    if (list->next == NULL) {
        Data ret = list->data;
        *plist = NULL;
        return ret;
    }

    Node* t;
    for (t = *plist; t->next->next != NULL; t = t->next);
    Data ret = t->next->data;
    free(t->next);
    t->next = NULL;
    return ret;
}

//Data erase(Node** plist, int i) {
//    if (is_list_empty(*plist))
//        return 404;
//
//    if (i == 0)
//        return pop_front(plist);
//
//    Node* t;
//    int j;
//    for (t = *plist, j = 0; t->next != NULL; t = t->next, j++);
//
//    if (i == j)
//        return pop_back(plist);
//
//    if (i > j)
//        return 404;
//
//    for (t = *plist, j = 0; j < i - 1; t = t->next, j++);
//
//
//    Node* cur = t->next;
//    Data ret = cur->data;
//    t->next = cur->next;
//    free(cur);
//    return ret;
//}

Data erase(Node** plist, int i) {
    if (is_list_empty(*plist))
        return 404;

    if (i == 0)
        return pop_front(plist);

    Node* cur = *plist;
    Node* prev = NULL;
    int j = 0;

    while (cur != NULL && j != i) {
        prev = cur;
        cur = cur->next;
        j++;
    }

    if (cur == NULL)
        return 404;

    Data ret = cur->data;

    if (prev == NULL)
        *plist = cur->next;
    else
        prev->next = cur->next;

    cur->next = NULL;
    free(cur);
    return ret;
}