#define LEN 20
struct queue
{
       int head;
       int tail;
       int a[20];
};

void enqueue(struct queue *queue,int elem);
int dequeue(struct queue *queue);




