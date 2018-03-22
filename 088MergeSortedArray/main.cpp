#include <iostream>
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) //其实可以从最后一位开始比较，题意说了nums1的大小肯定可以容下m+n，所以可以把最大的放nums1的m+n-1那一位去就可以不再创建一个tmp了
    {
        int i, j, count;
        vector<int> tmp;
        nums1 = (m == 0 || n == 0) ? ((m == 0) ? nums2 : nums1) : nums1;
        i = 0;
        j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                tmp.push_back(nums1[i]);
                i++;
            }
            else
            {
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        if (i != m)
            for (; i < m; i++)
                tmp.push_back(nums1[i]);
        else
            for (; j < n; j++)
                tmp.push_back(nums2[j]);
        nums1 = tmp;
    }
};

int main()
{
    return 0;
}