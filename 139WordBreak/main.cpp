#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        tr1::unordered_map<string, int> dict;
        vector<string> dp(s.length(),"");
        int minlen=wordDict[0].length();
        for(string tmp:wordDict)
        {
            dict[tmp]=1;
            minlen=min(tmp.length(),minlen);
        }
        if(s.length()<minlen)
            return false;
        if(dict[s.substr(0,minlen)]==1)
            dp[minlen-1]=s.substr(0,minlen);
        for(int i=minlen;i<s.length();i++)
        {
            if(dp[i-1].length())
            {
                if(dict[s.substr(0,i+1)]==0)
                    dp[i-1]=s.substr(0,i+1);
            }
            else
            {
                
            }
        }
    }
};