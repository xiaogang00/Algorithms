#define LEN 20

struct tqueue
{
       int head;
       int tail;
       int array[LEN];     
};

void enqueue_head(struct tqueue *tqueue,int elem);
void enqueue_tail(struct tqueue *tqueue,int elem);
int dequeue_head(struct tqueue *tqueue);
int dequeue_tail(struct tqueue *tqueue);
