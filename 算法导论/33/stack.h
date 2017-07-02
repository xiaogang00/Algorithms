#define LEN 20
struct stack
{
       int top;
       int array[LEN];
};

void push(struct stack *stack,int elem);
int pop(struct stack *stack);
