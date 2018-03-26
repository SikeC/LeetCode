#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
  public:
    vector<vector<int> > generate(int numRows) //我只想到这种复杂度的解法，就是一层一层累加慢慢做
    {
        vector<vector<int> > ret; 
        vector<int> tmp;
        if(numRows == 0)
            return ret;
        tmp.push_back(1);
        ret.push_back(tmp);
        tmp.clear();
        for (int i = 0; i < numRows - 1; i++)
        {
            tmp.push_back(1);
            for (int j = 0; j < ret[i].size(); j++)
            {
                if (j + 1 == ret[i].size())
                {
                    tmp.push_back(ret[i][j]);
                    continue;
                }
                tmp.push_back(ret[i][j] + ret[i][j + 1]);
            }
            ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
    }
};