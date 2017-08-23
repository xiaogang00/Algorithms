
struct tree_node
{
       char key;
       struct tree_node *left,*right;
};

struct tree_node*& string_to_tree(std::string &str);
void trace_tree(struct tree_node *b_tree);

