#ifndef NODE_H
#define NODE_H
/**************************
seq 从0开始 
**************************/
struct node
{
       int seq;
       int weight;                //适当的时候用 
       struct node *next;
};

#endif
