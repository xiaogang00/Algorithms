struct node
{
       int data;
       struct node *next;
};

struct queue
{
       struct node *head;
       struct node *tail;
};
void init(struct queue*& queue);

