#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string tmp;
        int i, j;
        bool flag;
        flag = false;
        if (strs.size() == 0)
        {
            tmp = "";
            return tmp;
        }
        if (strs.size() == 1)
        {
            tmp = strs[0];
            return tmp;
        }
        tmp = strs[0];
        for (i = 1; i < strs.size(); i++)
        {
            for (j = 0; j < tmp.size() && j < strs[i].size(); j++)
            {
                if (tmp[j] != strs[i][j])
                {
                    tmp.erase(j);
                    flag = true;
                    goto loop;
                }
            }
        loop:
            if (flag == false && tmp.size() > strs[i].size())
            {
                tmp = strs[i];
            }
        }
        return tmp;
    }
};
int main(void)
{
    vector<string> strs;
    Solution s;
    string str;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    str = s.longestCommonPrefix(strs);
    cout << str << endl;
    return 0;
}
