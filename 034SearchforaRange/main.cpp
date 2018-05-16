#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]==target)
          {
              if(ret[0]==-1)
              {
                  ret[0]=i;
              }
              else
              {
                  ret[1]=i;
              }
          }
        }
        if(ret[0]!=-1&&ret[1]==-1)
        {
            ret[1]=ret[0];
        }
        return ret;
    }
};