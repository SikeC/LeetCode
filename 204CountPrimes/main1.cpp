#include <iostream>
#include <math.h>
class Solution
{
  public:
    int countPrimes(int n)
    {
        if (--n < 2)
            return 0;
        int m = (n + 1) / 2, count = m, k, u = (sqrt(n) - 1) / 2;
        bool notPrime[m] = {0};

        for (int i = 1; i <= u; i++)
            if (!notPrime[i])
                for (k = (i + 1) * 2 * i; k < m; k += i * 2 + 1)
                    if (!notPrime[k])
                    {
                        notPrime[k] = true;
                        count--;
                    }
        return count;
    }
};