struct tree_node
{
       std::string key;
       int flag;
       struct tree_node *left,*right;
};

void init(struct tree_node*& b_tree);
void insert_node(struct tree_node* b_tree,std::string str);
void trace_tree(struct tree_node *b_tree);
