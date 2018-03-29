#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    { //只要后一天能比前一天大，那么我就买了再买，只要在涨，那么结果就一直最高，跌了那天不买
        int sum = 0;
        int ret = 0;
        if (prices.size() < 2)
            return 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            sum = prices[i + 1] - prices[i];
            if (sum > 0)
            {
                ret += sum;
            }
        }
        return ret;
    }
};