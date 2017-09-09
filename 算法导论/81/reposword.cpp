#include "reposword.h"

using namespace std;

vector<pair<string,string> > sign_vector;
string generate_sign(string word)
{
     string sign_word(word);
     int len=sign_word.size();
     sort(sign_word.begin(),sign_word.end());
     return sign_word;
}
void generate_sign_vector(string word)
{
     string sign_word(generate_sign(word));
     sign_vector.push_back(make_pair(sign_word,word));
}
bool smaller(const pair<string,string> s1,const pair<string,string> s2)
{
     return s1.first<s2.first;
}
void sort_sign_vector()
{
     stable_sort(sign_vector.begin(),sign_vector.end(),smaller);
}
void print(char *outfilename)
{
     fstream outfile(outfilename,fstream::out);
     vector<pair<string,string> >::iterator iter=sign_vector.begin();
     string flag(iter->first);
     for(;iter!=sign_vector.end();iter++)
     {
      if(iter->first!=flag)
      {
       outfile<<endl;
       flag=iter->first;
      }
      outfile<<iter->second<<" ";
     }
     outfile.close();
}

