#include <iostream>
#include <vector>

using namespace std;

struct node
{
       int data;
       struct node *next;
};

void input_v(vector<int> &v);
void print_v(const vector<int> &v);
void sort(vector<int> &v);
