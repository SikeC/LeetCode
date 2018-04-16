#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
  public:
    bool isIsomorphic(string s, string t)//通过两个map来确定唯一的对应关系
    {
        map<char, char> stmap;
        map<char, char> tsmap;
        if(s.length()!=t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (!stmap.count(s[i]))
                stmap[s[i]] = t[i];
            else if (stmap[s[i]] != t[i])
                return false;
            if (!tsmap.count(t[i]))
                tsmap[t[i]] = s[i];
            else if (tsmap[t[i]] != s[i])
                return false;
        }
        return true;
    }
};