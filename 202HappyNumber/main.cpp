#include <iostream>
#include <set>
using namespace std;
class Solution
{
  public:
    bool isHappy(int n)//这个4是网上的人算出来的，我看到个很有意思的算循环的，就是一个数每次算两次，一个数每次算一次，循环总会相等，一也总会相等，只要相等就出来看看是不是等于1就行
    {
        int m = 0;
        if (n == 1 | n == -1)
            return true;
        while (1)
        {
            while (n != 0)
            {
                m += (n % 10) * (n % 10);
                n /= 10;
            }
            if (m == 1)
                return true;
            if (m == 4)
                return false;
            n = m;
            m = 0;
        }
    }
};