#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

void print(stack st) {
    for (int i = 0; i < st.n; i++)
        printf("%d ", st.a[i]);
    printf("\n");
}

void init(stack *st) {
    st->n = 0;
}

void push(stack *st, data_s x) {
    st->a[st->n] = x;
    st->n++;
}

data_s pop(stack *st) {
    return st->a[--st->n];
/*    data_s ret = st->a[st->n-1];
    st->n--;
    return ret; */
}

bool is_empty(stack st) {
    if (st.n == 0)
        return true;
    return false;
}

data_s top(stack st) {
    if (st.n == 0)
        return 404;
    return st.a[--st.n];
}
