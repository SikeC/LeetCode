#include <iostream>
#include <vector>
using namespace std;

int x=[](){
   std::ios::sync_with_stdio(false);  //关闭STDIN和CIN同步 减少CIN读入的时间，可以减少50%以上。//这一句是从discuss看到的，虽然不懂，但是真的减少了一半时间
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> NetChangeArray(nums.size());
        int i;
        int tmp = 0;
        int sum = 0;
        int maxsum;
        if (nums.size() == 0)
        {
            return 0;
        }
        maxsum = nums[0];
        for (i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maxsum)
            {
                maxsum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxsum;
    }
};

int main(void)
{
    int num[] = {31,-41,59,26,-53,58,97,-93,-23,84};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}