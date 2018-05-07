#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int max=0;
        if(!n)
            return 0;
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j=i-1;  j>=0; j--)
            {
                if (nums[j] < nums[i])
                {
                    if(dp[i]<dp[j]+1)
                        dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]>max)
                max=dp[i];
        }
        return max;
    }
};

int main()
{
    Solution s;
    int a[] = {11,12,13,14,15,6,7,8,101,18};
    vector<int> num(a, a + 10);
    s.lengthOfLIS(num);
    return 0;
}
