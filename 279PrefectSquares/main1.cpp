#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
  int numSquares(int n)
  {
    int integer;
    if (n < 4)
      return 1;
    double square = sqrt(n);
    if (square == (int)square)
    {
      return 1;
    }
    else
    {
      int tmp = n / 2;
      square = sqrt(tmp);
      double decimal = square - (int)square;
      integer = (int)square;
      if (decimal >= 0.5)
        integer++;
    }
    return 1 + numSquares(n - integer * integer);
  }
};