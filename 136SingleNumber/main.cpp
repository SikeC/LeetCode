#include <iostream>
#include <vector>
using namespace std;
static int x=[](){
			// toggle off cout & cin, instead, use printf & scanf
		    std::ios::sync_with_stdio(false);
		    // untie cin & cout
		    cin.tie(NULL);
		    return 0;
		}();

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int ret=0;//异或计算
        for(int i=0;i<nums.size();i++)
        {
            ret^=nums[i];
        }
        return ret;
    }
};

