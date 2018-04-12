#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();   
        k=n-k%n;
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};