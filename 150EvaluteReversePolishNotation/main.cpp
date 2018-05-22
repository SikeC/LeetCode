#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
using namespace std;
class Solution
{
  public:
    int evalRPN(vector<string> &tokens)//逆波兰很简单，就是一个栈模型搞定，遇见了运算符就把栈模型中弹出两个数运算，然后再存入里面就OK
    {
        int ret = 0;
        stack<int> tmp;
        if (!tokens.size())
            return ret;
        for (auto i : tokens)
        {
            if (i[i.size()-1] >= '0' && i[i.size()-1] <= '9')
            {
                int j = atoi(i.c_str());
                tmp.push(j);
            }
            else
            {
                int a = tmp.top();
                tmp.pop();
                int b = tmp.top();
                tmp.pop();
                int c;
                switch (i[0])
                {
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = b - a;
                    break;
                case '*':
                    c = a * b;
                    break;
                case '/':
                    c = b / a;
                    break;
                }
                tmp.push(c);
            }
        }
        ret = tmp.top();
        return ret;
    }
};