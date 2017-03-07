#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
    map<int,float> ploy1,ploy2,res;
    map<int,float>::iterator it_m1,it_m2;
    float coef;  //系数 
    int expn;    //指数 
    while(cin>>coef>>expn)
    {
     ploy1.insert(make_pair(expn,coef));
    }
    cin.clear();
    cin.sync();
    while(cin>>coef>>expn)
    {
     ploy2.insert(make_pair(expn,coef));
    }
    for(it_m1=ploy1.begin();it_m1!=ploy1.end();++it_m1)
    {
     map<int,float>::iterator it_find=ploy2.find(it_m1->first);
     if(it_find==ploy2.end())
     ploy2.insert(*it_m1);
     else
     it_find->second+=it_m1->second;
    }
    for(it_m1=ploy2.begin();it_m1!=ploy2.end();++it_m1)
    {
     cout<<it_m1->second<<" "<<it_m1->first<<endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
