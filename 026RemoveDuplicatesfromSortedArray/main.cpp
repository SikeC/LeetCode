#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    { //根据题意可以得出其实不用删除数组，把所有数排到前面然后返回一个pos就行
        int i;
        int count = 0;
        if (nums.size() == 0)
        {
            return 0;
        }
        for (i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] != nums[i + 1])
            {
                count++;
                nums[count] = nums[i + 1];
            }
        }
        return count + 1;
    }
};
int main(void)
{
    vector<int> num;
    Solution s;
    clock_t startTime, endTime;
    int ret;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    startTime = clock();
    ret = s.removeDuplicates(num);
    endTime = clock();
    cout << ((double)(endTime - startTime) / CLOCKS_PER_SEC) << endl;
    return 0;
}