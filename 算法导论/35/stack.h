#define LEN 20

struct stack
{
       int top;
       int array[LEN];
};

struct queue
{
       struct stack stacka;
       struct stack stackb;
};
void enqueue(struct queue *queue,int elem);
int dequeue(struct queue *queue);
