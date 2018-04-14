#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int countPrimes(int n)
    {
        vector<bool> isPrimes(3, false);
        int count=0;
        if (n < 3)
            return 0;
        isPrimes.resize(n+1);
        for (int i = 4; i < n+1; i = i + 2)
        {
            isPrimes[i] = true;
        }
        for (int i = 3; i < n+1; i++)
        {
            if (!isPrimes[i])
            {
                int j = 3;
                while (i * j <= n)
                {
                    if (isPrimes[i * j] == false)
                    {
                        isPrimes[i * j] = true;
                    }
                    j++;
                }
            }
        }
        for(bool i:isPrimes)
        {
            if(!i)
                count++;
        }
        return count-2;
    }
};
int main()
{
    Solution s;
    s.countPrimes(15);
    return 0;
}