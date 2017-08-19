#define LEN 5

struct queue
{
       int head;
       int tail;
       int array[LEN];
};

struct stack
{
       struct queue queuea;
       struct queue queueb;
};
void push(struct stack *stack,int elem);
int pop(struct stack *stack);
