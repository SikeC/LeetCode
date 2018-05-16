#include <iostream>
#include <vector>
using namespace std;//不知道为什么就是运行出错
class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i;
        int j;
        if (!matrix.size() || !matrix[0].size())
            return false;
        i = 0;
        j = matrix[0].size() - 1;
        while (j >= 0)
        {
            if (matrix.size() == i)
                return false;
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] < target)
                i++;
            if (matrix[i][j] > target)
                j--;
        }
        return false;
    }
};

int main()
{
    vector<int> b{1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> a(1, b);
    Solution s;
    s.searchMatrix(a, 4);
    return 0;
}