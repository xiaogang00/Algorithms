#include "calculate.h"

using namespace std;

map<char,int> ops;

void init_ops()
{
     ops.insert(make_pair(')',0));
     ops.insert(make_pair('+',1));
     ops.insert(make_pair('-',1));
     ops.insert(make_pair('*',2));
     ops.insert(make_pair('/',2));
     ops.insert(make_pair('(',3));
}

char to(char ch,char a,char b)
{
    int res;
    char aa[2];
    aa[0]=a;
    aa[1]='\0';
    char bb[2];
    bb[0]=b;
    bb[1]='\0';
    int x=atoi(aa);
    int y=atoi(bb);
    switch(ch)
    {
    case '+':
         res=x+y;
         break;
    case '-':
         res=x-y;
         break;
    case '*':
         res=x*y;
         break;
    case '/':
         res=x/y;
         break;
    default:
         break;
    }
    return res+'0';
}
int calculate(string formula)
 {
    stack<pair<char,int> > op_stack;
    stack<int> num_stack;
    map<char,int>::iterator m_iter;
    for(string::iterator s_iter=formula.begin();s_iter!=formula.end();s_iter++)
    {
     if(isdigit(*s_iter))
     {
      num_stack.push(*s_iter);
     }
     else
     {
      if(op_stack.empty())                //操作栈空 
      {
       if((m_iter=ops.find(*s_iter))==ops.end())
       {
        cout<<"expression is error!"<<endl;
        return -1;
       }
       op_stack.push(make_pair(*s_iter,m_iter->second));
      }
      else                               //操作栈非空 
      {
          if((m_iter=ops.find(*s_iter))==ops.end())
          {
           cout<<"expression is error!"<<endl;
           return -1;
          }

          while(!num_stack.empty()&&!op_stack.empty()&&m_iter->second<=op_stack.top().second)        // 运算 
          {
           if(op_stack.top().first=='(')
           {
            if(*s_iter==')')
            {
            op_stack.pop();
            }
            break;
           }
           char a=num_stack.top();
           num_stack.pop();
           char b=num_stack.top();
           num_stack.pop();
           char ch=op_stack.top().first;
           op_stack.pop();
           char res=to(ch,a,b);
           num_stack.push(res);
          }               //end while
          if(m_iter->first!=')')
          {
            op_stack.push(*m_iter);             //op栈空了，或者是遇到优先级小的了 
          }
      }
     }
    }
    if(!op_stack.empty())
    {
                         
           char a=num_stack.top();
           num_stack.pop();
           char b=num_stack.top();
           num_stack.pop();
           char ch=op_stack.top().first;
           op_stack.pop();
           char res=to(ch,a,b);
           num_stack.push(res);
    }
    char ret=num_stack.top();
    char retret[2];
    retret[0]=ret;
    retret[1]='\0';
    return atoi(retret);
}
