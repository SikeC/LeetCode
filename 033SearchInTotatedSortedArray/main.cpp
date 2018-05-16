#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        if(!nums.size())  
            return -1;  
        int begin=0;  
        int end=nums.size()-1;        
        while(begin<=end){  
            int mid=begin+(end-begin)/2;  
            if(nums[mid]==target)  
                return mid;  
            if(nums[mid]>=nums[begin]){      
                if(nums[begin]<=target&&target<nums[mid])    
                    end=mid-1;  
                else  
                    begin=mid+1;  
            }else{                    
                if(nums[mid]<target&&target<=nums[end])  
                    begin=mid+1;  
                else  
                    end=mid-1;  
            }      
        }  
        return -1;
    }
};