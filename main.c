#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "list.h"

int main() {

    int b[] = {1, 2, 3};
    Node* lst = arr2list(b, 3);
    print_list(lst);

    push_back(&lst, 15);
    push_front(&lst, -1);
    push_back(&lst, -2);
    print_list(lst);

    insert(&lst, 7, 3);
    print_list(lst);

    pop_front(&lst);
    print_list(lst);

    pop_back(&lst);
    print_list(lst);

    return 0;
}
