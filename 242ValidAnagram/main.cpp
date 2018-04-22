#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        if(s.size()!=t.size())
            return false;
        for(int i =0;i<s.size();i++)
        {
            a[s[i]-97]++;
            b[t[i]-97]++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
};