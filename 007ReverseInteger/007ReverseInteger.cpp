#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        long long tmp;
        long long res;
        long long buf;
        buf = x;;
        bool flag = true;
        if (buf < 0)
        {
            flag = false;
            buf = -buf;
        }
        if (buf == 0)
        {
            return 0;
        }
        res = 0;
        tmp = 10;
        while (buf >= tmp)
        {
            res = res * 10 + (buf % tmp) / (tmp / 10);
            tmp *= 10;
        }
        res = res * 10 + (buf % tmp) / (tmp / 10);
        if (!flag)
        {
            res = -res;
        }
        if (res > INT_MAX || res < INT_MIN)
        {
            return 0;
        }
        return res;
    }
};

int main(void)
{
    int x;
    Solution s;
    while (1)
    {
        x = -2147483648;
        cout << s.reverse(x) << endl;
    }
    return 0;
}