struct treap_node
{
       int key;
       int priority;
       struct treap_node *left,*right;
};

void insert_node(struct treap_node *&treap,int key,int p);
void trace_tree(struct treap_node *treap);
