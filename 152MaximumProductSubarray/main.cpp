#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxProduct(vector<int> &nums) //dp数组两个成员，到当前成员的正数是多少，负数是多少，然后乘起来，比较最大的正数
    {
        if (!nums.size())
            return 0;
        vector<pair<int, int>> dp(nums.size());
        if (nums[0] >= 0)
        {
            dp[0].first = nums[0];
            dp[0].second = 0;
        }
        else
        {
            dp[0].first = 0;
            dp[0].second = nums[0];
        }
        int ret=nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                dp[i].first = max(dp[i - 1].first * nums[i], nums[i]);
                dp[i].second = dp[i - 1].second * nums[i];
            }
            else
            {
                dp[i].first = dp[i - 1].second * nums[i];
                dp[i].second = min(dp[i - 1].first * nums[i], nums[i]);
            }
            ret=max(ret,dp[i].first);
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{7,-2,-4};
    Solution s;
    s.maxProduct(nums);
    return 0;
}