#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> myMap;
        vector<char> tmpl;
        myMap['('] = ')';
        myMap['{'] = '}';
        myMap['['] = ']';
        if (s.size() % 2 != 0)
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '('||s[i]=='['||s[i]=='{')
            {
                tmpl.push_back(s[i]);
            }
            else
            {
                if(tmpl.size() == 0)
                {
                    return false;
                }
                if(myMap[tmpl.back()] == s[i])
                {
                    tmpl.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        return tmpl.size() == 0;
    }
};

int main(void)
{
    Solution s;
    string s1;
    s1="{}{}()[][()[])";
    s.isValid(s1);
    return 0;
}