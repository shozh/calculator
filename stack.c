typedef struct {
    int a[1000];
    int n;
} stack;

void print(stack *st) {
    for (int i = 0; i < st->n; i++)
        printf("%d ", st->a[i]);
    endl;
}


void push(stack *st, int x);
int pop(stack *st);
void init(stack *st);

int is_empty(stack *st);

