#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret;
        int cursor;
        int next;
        bool end = false;
        ret.push_back(1);
        if (!rowIndex)
        {
            return ret;
        }
        for (int j = 0; j < rowIndex; j++)
        {
            for (int i = 0; i < j+1; i++)
            {
                if (i == 0)
                {
                    cursor = ret[i];
                }
                else
                {
                    cursor = next;
                }
                if (i == ret.size() - 1)
                    ret.push_back(1);
                else
                {
                    next = ret[i + 1];
                    ret[i + 1] = cursor + next;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    s.getRow(3);
    return 0;
}