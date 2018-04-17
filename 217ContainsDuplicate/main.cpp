#include <iostream>
#include <vector>
#include <set>
using namespace std;
static int x = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> a;
        for (int i : nums)
        {
            if (!a.insert(i).second)
                return true;
        }
        if (!a.size())
            return false;
        return false;
    }
};