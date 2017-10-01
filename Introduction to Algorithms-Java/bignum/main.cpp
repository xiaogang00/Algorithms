#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void add(string augend1,string augend2,string &res)
{
/*ÿ�ν���֮�����resΪ0*/ 
     fill(res.begin(),res.end(),'0');
     int saLen = augend1.size();
     int sbLen = augend2.size(); 
     int maxLen = saLen;
     if (saLen > sbLen)
     {
        maxLen = saLen;
        int mergin = saLen - sbLen;
        for (int i = 0;i < mergin;i++)
        {
            augend2 = '0' + augend2;
        }
     }
     else if (saLen < sbLen)
     {
          maxLen = sbLen;
          int mergin = sbLen - saLen;
          for (int i = 0;i < mergin;i++)
          {
              augend1 = '0' + augend1;
          }
     }
     int k = res.size() - 1;
     for (int i = maxLen -1;i >= 0;i--)
     {
         int stepAdd =res[k] - '0' + augend1[i] - '0' + augend2[i] - '0';
         res[k] = stepAdd % 10 + '0';
         res[k - 1] += (stepAdd / 10);
         k--;
     }
} 
void sub(string dec1,string dec2,string &res)
{
/*֧�ִ�����С����Ϊ������������ dec1 < dec2  �Ļ�����ֵ�Ի����ټ���
 ���Ľ���ۼӵ�res�У����ֻ�������DEC1��DEC2��ֵ����Ҫ���res�������*/
     fill(res.begin(),res.end(),'0'); 
     int i = 0;
     while (dec1[i] == '0')
     i++;
     int aLen = dec1.size() - i;
     int j = 0;
     while (dec2[j] == '0')
     j++;
     int bLen = dec2.size() - j;
     if (aLen < bLen)
     {
        string temp = dec1;
        dec1 = dec2;
        dec2 = temp;
     }
     else if( aLen == bLen)
     {
          while (i < dec1.size() && dec1[i] == dec2[j])
          {
                i++;
                j++;
          }
          if (i == dec1.size())
          return;
         if (dec1[i] < dec2[j])
         {
            string temp = dec1;
            dec1 = dec2;
            dec2 = temp;
         }
     }
     else;
     int maxLen = dec1.size();
     if (dec1.size() > dec2.size())
     {
        int error = dec1.size() - dec2.size();
        for (int m = 0;m < error;m++)
        dec2 = '0' + dec2;
     }
     else if (dec2.size() > dec1.size())
     {
        int error = dec1.size() - dec2.size();
        for (int m = 0;m < error;m++)
          dec1 = '0' + dec1;
     }
     int r = res.size() - 1;
     for (int k = maxLen - 1;k >= 0;k--)
     {
         if (dec1[k] < dec2[k])
         {
            dec1[k - 1] = dec1[k - 1] - 1;
            res[r--] = dec1[k]+10- dec2[k]+'0'; 
         }
         else
         {
             res[r--] = dec1[k] - dec2[k]+'0';
         }
     }
}

void multiply(string mul1,string mul2,string &result)
{
/*���Ľ�����浽 result�У���ʱ��Ҫ���result�������*/ 
      fill(result.begin(),result.end(),'0');
      for (int i = mul2.size() - 1;i >= 0;i--)
     {
         for (int j = mul2[i]-'0' - 1;j >= 0;j--)
         {

             add(result,mul1,result);
         }
         mul1 = mul1 + '0';
     }
}
int bigger(string num1,string num2)
{
/*num1 > num2 return 1
  num1 < num2 return -1
  num2 ==num2 return 0 */
    int i = 0;
    int j = 0;
    while (num1[i] == '0')
    i++;
    while (num2[j] == '0')
    j++;
    int num1Len = num1.size() - i;
    int num2Len = num2.size() - j;
    if (num1Len > num2Len)
       return 1;
    else if (num1Len < num2Len)
         return -1;
    else
    {
        while (i < num1.size() && num1[i] == num2[j])
        {
              i++;
              j++;
        }
        if (i == num1.size())
           return 0;
        else
        {
            if (num1[i] > num2[j])
               return 1;
            else return -1;
        }
    }
}
void div(string diva,string divb,string &res,string &remander)
{
/*res��remander��λ�����������*/ 
     res = "";
     remander = "";
     for (int i = 0;i < diva.size();i++)
     {
         remander = remander + diva[i];
         res = res + '0';
         while (bigger(remander,divb) != -1)
         {
            sub(remander,divb,remander);
            res[res.size() - 1]++;
         }
     }
}
int main(int argc, char *argv[])
{
    string sa("0028624083");
    string sb("25602");
    string divres;
    string divremander;
    div(sa,sb,divres,divremander);
    cout << divres <<" "<<divremander<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
