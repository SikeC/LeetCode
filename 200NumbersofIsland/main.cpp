#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    void setZero(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] != '0')
        {
            setZero(grid, i - 1, j);
        }
        if (j > 0 && grid[i][j - 1] != '0')
        {
            setZero(grid, i, j - 1);
        }
        if (i < grid.size() - 1 && grid[i + 1][j] != '0')
        {
            setZero(grid, i + 1, j);
        }
        if (j < grid.at(0).size() - 1 && grid[i][j + 1] != '0')
        {
            setZero(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    setZero(grid, i, j);
                }
            }
        }
        return count;
    }
};