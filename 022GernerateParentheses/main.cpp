#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
class Solution
{
  public:
   vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};

int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}
