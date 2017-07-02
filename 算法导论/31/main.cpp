#include <cstdlib>
#include <iostream>
#include <vector>

#define LEN 20


using namespace std;
int topa=-1;
int topb=LEN;

void print_v(const vector<int> &v)
{
     for(vector<int>::const_iterator c_iter=v.begin();c_iter!=v.end();++c_iter)
     cout<<*c_iter<<" ";
     cout<<endl;
}
void init(vector<int> &v)
{
     int topa=-1;
     int topb=v.size();
}

void pusha(vector<int> &v,int elem)
{
     if(topa>=topb-1)
     {
      cout<<"full"<<endl;
      return;
     }
     v[++topa]=elem;
}
void pushb(vector<int> &v,int elem)
{
     if(topa>=topb-1)
     {
      cout<<"full"<<endl;
      return;
     }
     v[--topb]=elem;
}
int popb(vector<int> &v)
{
    int elem;
    if(topb>=v.size())
    {
     cout<<"empty"<<endl;
     return -1;
    }
    else
    {
    elem=v[topb];
    ++topb;
    return elem;
    }
}
int popa(vector<int> &v)
{
    int elem;
    if(topa<=-1)
    {
     cout<<"empty"<<endl;
     return -1;
    }
    else
    {
    elem=v[topa];
    --topa;
    return elem;
    }
}
int main(int argc, char *argv[])
{
    vector<int> v(LEN);
    for(int i=0;i<10;++i)
    {
     pusha(v,i);
    }
    for(int i=0;i<10;++i)
    {
     pushb(v,i);
    }
    print_v(v);
    pusha(v,33);
    int data=popb(v);
    cout<<data<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
