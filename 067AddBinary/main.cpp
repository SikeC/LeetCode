#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
static vector<string> strs = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return vector<string>{};
}(); 
class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int sum;
        int carry = 0;
        int i, j;
        string ret;
        for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--)
        {
            sum = (a[i] + b[j] - 96 + carry) / 2;
            carry = (a[i] + b[j] - 96 + carry) % 2;
            ret.push_back(sum + 48);
        }
        if (i > j)
        {
            for (; i >= 0; i--)
            {
                sum = (a[i] - 48 + carry) / 2;
                carry = (a[i] - 48 + carry) % 2;
                ret.push_back(sum + 48);
            }
        }
        else if(i < j)
            {
                for (; j >= 0; j--)
                {
                    sum = (b[j] - 48 + carry) / 2;
                    carry = (b[j] - 48 + carry) % 2;
                    ret.push_back(sum + 48);
                }
            }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    return 0;
}