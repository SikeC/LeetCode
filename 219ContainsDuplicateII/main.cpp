#include <iostream>
#include <vector>
#include <map>
using namespace std;

static auto x = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> mymap;
        pair<map<int, int>::iterator, bool> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            ret = mymap.insert(make_pair(nums[i], i));
            if (!ret.second)
                if (i - ret.first->second <= k)
                    return true;
                else
                    mymap[nums[i]] = i;
        }
        return false;
    }
};