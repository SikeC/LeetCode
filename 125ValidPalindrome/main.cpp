#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        int i, j;
        bool right, left;
        if (!s.size())
            return true;
        transform(s.begin(), s.end(), s.begin(), ::tolower);  //转换成小写，其实也可以不转化可以在下面比较转化会更快比如检测到是大写就加上32来做更快，只是麻烦点
        for (i = 0, j = s.size() - 1; i < j;)
        {
            left = ('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z');
            right = ('0' <= s[j] && s[j] <= '9') || ('a' <= s[j] && s[j] <= 'z');
            if (left & right)
            {
                if (s[i] != s[j])
                    return false;
                i++;
                j--;
            }
            else if (!left & right)
            {
                i++;
            }
            else if (left & !right)
            {
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};