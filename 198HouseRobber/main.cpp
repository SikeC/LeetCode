#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums)//用贪心算法，每一个数都是最大，每一个数都是包括或者不包括，如果包括那么就是它和i-2之前的最优来，不包括，它就是i-1那个
    {
        int length=nums.size();
        int i;
        if(length == 0)
        {
            return 0;
        }
        if(length==1)
        {
            return nums[0];
        }
        if(length==2)
        {
            return nums[0]>nums[1]?nums[0]:nums[1];
        }
        nums[0]>nums[1]?nums[1]=nums[0]:nums[1]=nums[1];
        for(i=2;i<length;i++)
        {
            nums[i-1]>nums[i-2]+nums[i]?nums[i]=nums[i-1]:nums[i]+=nums[i-2];
        }
        return nums[i-1]>nums[i-2]?nums[i-1]:nums[i-2];
    }
};