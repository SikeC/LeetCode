#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return nums.size();
    }
};
int main()
{
    vector<int> nums(4);
    Solution s;
    int target;
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 5;
    nums[3] = 7;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}