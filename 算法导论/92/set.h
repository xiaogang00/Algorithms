#ifndef SET_H
#define SET_H
//#include "head.h"
#include "node.h"
extern array set_v;           //set¼¯ºÏ 
void make_set();
struct node* find(char c);
struct node* un(p_node &set1,p_node &set2);
#endif
