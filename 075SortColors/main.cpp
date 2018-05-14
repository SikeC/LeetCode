#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        vector<int> pos(3,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(pos[1]!=-1)
                {
                    swap(nums[i],nums[pos[1]]);
                    if(pos[0]==-1)
                    {
                        pos[0]=pos[1];
                    }
                    if(nums[pos[1]+1]==1)
                        pos[1]++;
                    else
                        pos[1]=-1;
                }
                else if(pos[2]!=-1)
                {
                    swap(nums[i],nums[pos[2]]);
                    if(pos[0]==-1)
                    {
                        pos[0]=pos[1];
                    }
                    pos[2]++;
                }
                else
                    pos[0]=i;
            }
            if(nums[i]==1)
            {
                if(pos[2]!=-1)
                {
                    swap(nums[i],nums[pos[2]]);
                    if(pos[1]==-1)
                    {
                        pos[1]=pos[2];
                    }
                    pos[2]++;
                }
                else if(pos[1]==-1)
                    pos[1]=i;
            }
            if(nums[i]==2)
            {
                if(pos[2]==-1)
                    pos[2]=i;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> a{1,1,0};
    s.sortColors(a);
    return 0;
}