#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        /*//用std自带函数做
        auto v = remove(nums.begin(), nums.end(), val);
        int sz = distance(nums.begin(), v);
        return sz;
        */
        int n;
        int i;
        n = nums.size();
        if (n == 0)//判断是不是空数组传入
        {
            return 0;
        }
        while (nums[n - 1] == val && n > 0)//从后向前查找第一个不是val的数，最后nums[n]是最后一个val
        {
            n--;
        }
        for (i = 0; i < n; i++)//从前往后挨个查找有没有val如果有就被后面的覆盖，然后再从n的位置查找下一个不是val的数
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
                while (nums[n - 1] == val)
                {
                    n--;
                }
            }
        }
        nums.resize(n);
        return n;
    }
};

int main(void)
{
    int ret;
    vector<int> num(4);
    num[0] = 3;
    num[1] = 2;
    num[2] = 3;
    num[3] = 3;
    Solution s;
    ret = s.removeElement(num, 2);
    cout << ret << endl;
    return 0;
}