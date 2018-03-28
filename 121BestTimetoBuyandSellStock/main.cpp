#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int sum = 0;
    int maxsum = 0;
    int tmp;
    int cursor;
    int size;
    int ret;
    vector<int> bak = prices;
    size = prices.size();
    if (size <= 1)
      return 0;
    tmp = prices[0];
    cursor = prices[1];
    for (int i = 1; i < size - 1; i++)
    {
      prices[i] = cursor - tmp;
      tmp = cursor;
      cursor = prices[i + 1];
    }
    prices[size - 1] = cursor - tmp;
    cursor = tmp = 0;
    for (int i = 1; i < size; i++)
    {
      sum += prices[i];
      if (sum > maxsum)
      {
        maxsum = sum;
        tmp = i;
        ret = bak[tmp] - bak[cursor];
      }
      if (sum < 0)
      {
        sum = 0;
        cursor = i;
      }
    }
    return ret;
  }
};

int main()
{
  vector<int> nums(5);
  Solution s;
  nums[0] = 7;
  nums[1] = 6;
  nums[2] = 4;
  nums[3] = 3;
  nums[4] = 1;
  cout << s.maxProfit(nums) << endl;
  return 0;
}