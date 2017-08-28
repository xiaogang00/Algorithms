struct avl_node
{
       int key;
       struct avl_node *left,*right;
       int height;
};

int height(struct avl_node *k);
int max_lr(struct avl_node *m,struct avl_node *n);
void rotate_left(struct avl_node*& k2);
void rotate_right(struct avl_node*& k2);
void double_rotate_left(struct avl_node*& k3);
void double_rotate_right(struct avl_node*& k3);
void insert_node(struct avl_node*& avl_tree,int elem);
void trace_tree(const struct avl_node* avl_tree);
