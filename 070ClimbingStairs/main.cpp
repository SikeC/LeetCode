#include <iostream>
using namespace std;

class Solution
{
  public:
    int climbStairs(int n) //实现 an = an_1+ an_2
    {
        int count;
        int an_1 = 1;
        int an_2 = 0;
        for (int i = 1; i <= n; i++)
        {
            count = an_1+an_2;
            an_2=an_1;
            an_1=count;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(2) << endl;
    return 0;
}