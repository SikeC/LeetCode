#include <iostream>
using namespace std;
class Solution
{
  public:
    int trailingZeroes(int n)
    {
        if(!n)
            return 0;
        int i = n/5;
        return i+trailingZeroes(i);
    }
};