#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
  public:
    vector<vector<bool>> vis;
    int n, m, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    bool _place(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
    bool dfs(vector<vector<char>> &board, string &word, int index, int row, int col)
    {
        if (index == word.size())
            return true;
        for (int k = 0; k < 4; ++k)
        {
            int i = row + dx[k], j = col + dy[k];
            if (_place(i, j) && !vis[i][j] && board[i][j] == word[index])
            {
                vis[i][j] = 1;
                if (dfs(board, word, index + 1, i, j))
                    return true;
                vis[i][j] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size(), m = n == 0 ? 0 : board[0].size();
        vis.assign(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == word[0])
                {
                    vis[i][j] = 1;
                    if (dfs(board, word, 1, i, j))
                        return true;
                    vis[i][j] = 0;
                }
        return false;
    }
};