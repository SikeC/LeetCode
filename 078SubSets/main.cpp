#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void subfunc(vector<vector<int> > &ret, vector<vector<int> > nums)
    {
        if (nums.size() == 1)
            return;
        for (int i = 1; i < nums.size(); i++)
        {
            vector<int> tmp = nums[0];
            vector<vector<int> > avg;
            tmp.insert(tmp.end(), nums[i].begin(), nums[i].end());
            avg.push_back(tmp);
            avg.insert(avg.end(), nums.begin() + i + 1, nums.end());
            ret.push_back(tmp);
            subfunc(ret, avg);
        }
        return;
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > ret;
        for (int i : nums)
        {
            vector<int> tmp(1, i);
            ret.push_back(tmp);
        }
        int n=ret.size();
        vector<vector<int> > num=ret;
        for(int i=1;i<n;i++)
        {
            subfunc(ret, num);
            num.erase(num.begin(),num.begin()+1);
        }
        vector<int> tmp;
        ret.push_back(tmp);
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,3,4};
    s.subsets(a);
    return 0;
}