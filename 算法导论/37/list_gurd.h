struct node
{
    int data;
    struct node *next;   
};

struct list
{
       struct node *head;
       struct node *tail;
};

void add_list(struct list *list,int elem);
void trace_list(struct list *list);
