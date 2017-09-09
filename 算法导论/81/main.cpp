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
     fstream infile(argv[1],fstream::in);//���ֵ� 
     string rword;
     while(infile>>rword)
     {
      generate_sign_vector(rword);   //����ǩ������ֵ� 
     }    
     sort_sign_vector();             //����ǩ������ 
     print(argv[2]);                 //�����λ�ʵ��ļ� 
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
