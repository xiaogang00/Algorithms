struct tree_node
{
       int key;
       struct tree_node *left,*right;
};

void insert_node(struct tree_node*& b_tree,int elem);
void trace_tree(struct tree_node* b_tree);
void p_trace_tree(struct tree_node* b_tree);
void l_trace_tree(struct tree_node* b_tree);


