#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    string countAndSay(int n)
    {
        string ret = "1";
        string tmp;
        int count;
        int i, j;
        if (n == 0)
        {
            return "";
        }
        if (n == 1)
        {
            return ret;
        }
        for (i = 0; i < n - 1; i++)
        {
            count = 1;
            for (j = 0; j < ret.size(); j++)
            {
                if (j + 1 != ret.size())
                {
                    if (ret[j] == ret[j + 1])
                    {
                        count++;
                    }
                    else
                    {
                        tmp.push_back(count + 48);
                        tmp.push_back(ret[j]);
                        count = 1;
                    }
                }
                else
                {
                    tmp.push_back(count + 48);
                    tmp.push_back(ret[j]);
                }
            }
            ret = tmp;
            tmp.clear();
        }
        return ret;
    }
};

int main(void)
{
    int i;
    Solution s;
    string str;
    for (i = 0; i < 10; i++)
    {
        str = s.countAndSay(i);
        cout << str.c_str() << endl;
    }
    return 0;
}