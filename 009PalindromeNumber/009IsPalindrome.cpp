#include <iostream>
using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        long long tmp;
        int oNum;
        int iNum;
        tmp = 0;
        iNum = x;
        if (iNum < 0)
        {
            return false;
        }
        oNum = iNum;
        while (iNum != 0)
        {
            tmp = tmp * 10 + iNum % 10;
            iNum /= 10;
        }
        return tmp == oNum;
    }
};

