#include <iostream>
#include <stdint.h>
using namespace std;
class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {//进行位运算，先分为俩俩一组，再四四一组，再88一组，再1616一组
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);
        return n;
    }
};