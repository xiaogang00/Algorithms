struct node 
{
       int data;
       struct node *next;
};
void add_list(struct node *list,int elem);
void reverse_list(struct node *list);
void print_list(struct node *list);
