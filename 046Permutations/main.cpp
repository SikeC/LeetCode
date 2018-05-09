#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int> > permute(vector<int> &nums)
    {
        vector<vector<int> > ret;
        vector<vector<int> > last;
        vector<int> next;
        if(nums.size()>1)
        {
            next.insert(next.begin(),nums.begin()+1,nums.end());
        }
        else
        {
            vector<int> a(1,nums[0]);
            ret.push_back(a);
            return ret;
        }
        last=permute(next);
        for(int i=0;i<last.size();i++)
        {
            for(int j=0;j<=last[i].size();j++)
            {
                vector<int> tmp=last[i];
                tmp.insert(tmp.begin()+j,nums[0]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{1,2,3};
    Solution s;
    s.permute(nums);
    return 0;
}