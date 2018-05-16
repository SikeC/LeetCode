#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ret=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0&&(i+1)<nums.size())
            {
                if(nums[0]>nums[1])
                {
                    ret = 0;
                    break;
                }
            }
            if(i==nums.size()-1&&i!=0)
            {
                if(nums[i]>nums[i-1])
                {
                    ret=i;
                    break;
                }
            }
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
            {
                ret=i;
                break;
            }
        }
        return ret;
    }
};