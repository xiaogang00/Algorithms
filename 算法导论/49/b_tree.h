struct tree_node
{
       int key;
       struct tree_node *parent,*left,*right;
};

void insert_node(struct tree_node*& b_tree,int data);
void trace_tree(struct tree_node *b_tree);
struct tree_node max_tree(struct tree_node* b_tree);
struct tree_node min_tree(struct tree_node* b_tree);
struct tree_node successor(struct tree_node * b_tree,struct tree_node *f_node);
struct tree_node predecessor(struct tree_node* b_tree,struct tree_node *f_node);
void delete_node(struct tree_node* b_tree,int key);
