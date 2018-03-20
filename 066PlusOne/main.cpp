#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ret;
        int carry = 1;//一个进位标志符就完事儿，就跟加法器一个原理
        int sum;
        int i;
        int j;
        for (i = digits.size() - 1; i >= 0; i--)
        {
            sum = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            ret.push_back(sum);
        }
        if (carry != 0)
        {
            ret.push_back(carry);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
    return 0;
}