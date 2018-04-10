#include <iostream>
#include <vector>
using namespace std;
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution
{
  public:
    int majorityElement(vector<int> &nums)//用多数投票法然后再检测一次是不是比二分之一大，时间O(n),空间O(1),我看到了一个直接排序取中值的，有点极端，这样必须存在才行
    {
        int cnt = 0;
        int vote;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!cnt)
                vote = nums[i];
            if (vote == nums[i])
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == vote)
                cnt++;
        }
        if (cnt >= (nums.size() / 2))
            return vote;
        else
            return 0;
    }
};