#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution
{
  public:
    Solution()
    {
        mymap['2'] = "abc";
        mymap['3'] = "def";
        mymap['4'] = "ghi";
        mymap['5'] = "jkl";
        mymap['6'] = "mno";
        mymap['7'] = "pqrs";
        mymap['8'] = "tuv";
        mymap['9'] = "wxyz";
    }

  public:
    map<char, string> mymap;
    vector<string> letterCombinations(string digits)
    {
        bool s = true;
        vector<string> ret;
        int n = digits.size();
        if (!n)
            return ret;
        vector<int> nums(n, 0);
        while (s)
        {
            string tmp;
            for (int i = 0; i < n; i++)
            {
                tmp.push_back(mymap[digits[i]][nums[i]]);
            }
            ret.push_back(tmp);
            nums[n - 1]++;
            int i = n - 2;
            while (i >= 0 && nums[i + 1] == mymap[digits[i + 1]].size())
            {
                nums[i + 1] = 0;
                nums[i]++;
                i--;
            }
            if(i==-1&&nums[0]==mymap[digits[0]].size())
                s=false;
        }
        return ret;
    }
};
