/*class node
{
      public:
             
              void add();          
      private:
              float coef;  //ϵ�� 
              int expn;    //ָ�� 
              class node *next;
}��*/
struct node
{
       float coef;
       int expn;
       struct node *next;
};
void create_ploy(struct node *ploy1,struct node *ploy2);
void input_ploy(struct node *ploy1,struct node *ploy2); 
void add_ploy(struct node *ploy1,struct node *ploy2);
void print_ploy(struct node *ploy);
