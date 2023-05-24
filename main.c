#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "list.h"

int main() {


    Node a = {3}, b = {17}, c = {21}, d = {10}, head = {7};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;
    Node* list = &a;

    print_list(list);

    list = &head;
    head.next = &a;

    print_list(list);

    push_front(&list, 2);

    print_list(list);

    return 0;
}
