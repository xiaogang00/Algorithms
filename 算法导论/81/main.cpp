#include <cstdlib>
#include <iostream>
#include "reposword.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=3)
    {
     cout<<"argument error"<<endl;
     exit(1); 
    }
    else
    {
     fstream infile(argv[1],fstream::in);//打开字典 
     string rword;
     while(infile>>rword)
     {
      generate_sign_vector(rword);   //生成签名后的字典 
     }    
     sort_sign_vector();             //基于签名排序 
     print(argv[2]);                 //输出变位词到文件 
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
