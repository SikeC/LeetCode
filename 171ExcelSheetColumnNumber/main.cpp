#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
  int titleToNumber(string s)
  {
    int ret = 0;
    for (char i : s)
    {
      ret = ret * 26 + i - 64;
    }
    return ret;
  }
};
int main()
{
  return 0;
}