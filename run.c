#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"
#include "list.h"
#include <string.h>
#include <iso646.h>
#include <ctype.h>
#include <math.h>

float abc = 5.34;
float xxx = -97.12;
float z = 23.23;
float asd = -2.5;
float ab12 = -1000.245;

#define putf(x) _Generic((x), \
    int: printf("%d\n", x), \
    float: printf("%f\n", x), \
    double: printf("%lf\n", x), \
    char*: printf("%s\n", x), \
    const char*: printf("%s\n", x) \
)

#define eps 0.001

float get_value(const char *name) {
    if (strcmp(name, "abc") == 0)
        return abc;
    if (strcmp(name, "xxx") == 0)
        return xxx;
    if (strcmp(name, "z") == 0)
        return z;
    if (strcmp(name, "asd") == 0)
        return asd;
    if (strcmp(name, "ab12") == 0)
        return ab12;
    return 404;
}

// ( -> 6001
// ) -> 6002
// + -> 6003
// - -> 6004
// * -> 6005
// / -> 6006
// ^ -> 6007

int issix(char c) {
    switch (c) {
        case '(':
            return 6001;
        case ')':
            return 6002;
        case '+':
            return 6003;
        case '-':
            return 6004;
        case '*':
            return 6005;
        case '/':
            return 6006;
        case '^':
            return 6007;
        default:
            return 0;
    }
}

Node* tokenize(char* s) {
    int n = strlen(s);
    Node* list = NULL;

    for (int i = 0; i < n; i++) {
        if (isalpha(s[i]) or (s[i] == '_')) {
            int start = i;
            while ((i < n) and (isalnum(s[i]) or s[i] == '_'))
                i++;

            int size = ((i == n) ? i - start + 1 : i - start);
            char* s_temp = (char*)malloc((size + 1) * sizeof(char));
            for (int j = start; j < start + size; j++)
                s_temp[j - start] = s[j];
            s_temp[size] = '\0';

            float val_temp = get_value(s_temp);
            if (fabs(val_temp - 404) < eps) {
                putf("Not able to tokenize the expression");
                exit(1);
            }
            else {
                push_back(&list, val_temp);
            }
            i--;
            free(s_temp);
        }
        if(issix(s[i])) {
            if ((i == 0 and s[i] == '-') or (i > 0 and s[i - 1] == '(' and s[i] == '-')) {
                i++;
                if (isdigit(s[i]) or (s[i] == '.')) {
                    int start = i;
                    i++;
                    if ((i < n) and (isdigit(s[i]) or s[i] == '.'))
                        i++;

                    int size = ((i == n) ? i - start + 1 : i - start);
                    char* s_temp = (char*)malloc((size + 2) * sizeof(char));
                    s_temp[0] = '-';
                    for (int j = start; j < start + size; j++)
                        s_temp[j - start + 1] = s[j];
                    s_temp[size] = '\0';

                    push_back(&list, (float)atof(s_temp));
                    i--;
                    free(s_temp);
                }

            }
            else
                push_back(&list, (float)issix(s[i]));
        }


        if (isdigit(s[i]) or (s[i] == '.')) {
            int start = i;
            i++;
            if ((i < n) and (isdigit(s[i]) or s[i] == '.'))
                i++;

            int size = ((i == n) ? i - start + 1 : i - start);
            char* s_temp = (char*)malloc((size + 1) * sizeof(char));
            for (int j = start; j < start + size; j++)
                s_temp[j - start] = s[j];
            s_temp[size] = '\0';

            push_back(&list, atof(s_temp));
            i--;
            free(s_temp);
        }

    }
    return list;
}

float factor(float x, int n) {
    float ret = 1;
    for (int i = 0; i < n; i++)
        ret *= x;
    return ret;
}


int main() {

    char* s = "(abc - xxx*2)/(z^3*(asd- 50))";
    Node* list = tokenize(s);
    print_list(list);

    stack nums;
    stack ops;
    init(&nums);
    init(&ops);

    Node* t;
    for (t = list; t != NULL, t = t->next) {
        float x = t->data;
        if (issix(x)) {
            if(fabs(top(ops) - 404) < eps)
                push(&ops, x);
            else {
                float up = top(ops);
                if (up == '+' or up == '-' or up == '(')
                    push(&ops, x);

            }
        }
    }

    return 0;
}