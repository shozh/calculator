#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iso646.h>
#include "stack.h"
#include "list.h"

#define put(x) _Generic((x), \
    int: printf("%d\n", x), \
    float: printf("%f\n", x), \
    double: printf("%lf\n", x), \
    char*: printf("%s\n", x), \
    const char*: printf("%s\n", x) \
)


int main() {

    char s[] = "1 + 3 * 10 / 2 + 7 * 21 / 7 / 3 - 10";
    char* token = strtok((char*)s, " ");
    int pm = 0;
    int md = 0;

    Node* list = NULL;
    bool start = true; // minus at the beginning

    while (token != NULL) {
        if ((strcmp(token, "+") == 0)) {
            pm++;
            push_back(&list, 5000);
        }
        else if ((strcmp(token, "-") == 0)) {
            if (start)
                push_front(&list, 0);
            pm++;
            push_back(&list, 5001);
        }
        else if ((strcmp(token, "*") == 0)) {
            md++;
            push_back(&list, 5002);
        }
        else if ((strcmp(token, "/") == 0)) {
            md++;
            push_back(&list, 5003);
        }
        else
            push_back(&list, atoi(token));
        start = false;
        token = strtok(NULL, " ");
    }

    print_list1(list);

    while (md) {
        Node* prev = NULL;
        Node* cur = list;
        Node* next = list->next;

        int i = 0;
         while (cur->data != 5002 and cur->data != 5003) {
            Node* tmp = next;
            prev = cur;
            cur = next;
            next = tmp->next;
            i++;
        }

        if (cur->data == 5002)
            cur->data = prev->data * next->data;
        else
            cur->data = prev->data / next->data;
        erase(&list, i-1);
        erase(&list, i);

        md--;
        print_list1(list);
    }

    while (pm) {
        Node* prev = NULL;
        Node* cur = list;
        Node* next = list->next;

        int i = 0;
        while (cur->data != 5000 and cur->data != 5001) {
            Node* tmp = next;
            prev = cur;
            cur = next;
            next = tmp->next;
            i++;
        }

        if (cur->data == 5000)
            cur->data = prev->data + next->data;
        else
            cur->data = prev->data - next->data;
        erase(&list, i-1);
        erase(&list, i);

        pm--;
        print_list1(list);
    }
    return 0;
}
