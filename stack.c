typedef struct {
    int a[1000];
    int n;
} stack;

void push(stack *st, int x);
int pop(stack *st);
void init(stack *st);
void print(stack *st);
int is_empty(stack *st);
