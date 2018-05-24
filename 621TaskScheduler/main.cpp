#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n) //我这道题有点问题，需要再看一下，思路是一样的，实现有问题
    {
        vector<int> c(26, 0);
        int m = tasks.size();
        int temp;
        for (char t : tasks)
        {
            c[t - 'A']++;
        }
        sort(c.begin(), c.end());
        int i = 25;
        while (i >= 0 && c[i] == c[25])
            i--;
        temp = (c[25] - 1) * (n + 1) + 25 - i;
        cout << temp;
        return max(m, temp);
    }
};

int main()
{
    vector<char> a;
    char b = 'A';
    a.push_back(b);
    a.push_back(b);
    a.push_back(b);
    b = 'B';
    a.push_back(b);
    a.push_back(b);
    a.push_back(b);
    Solution s;
    s.leastInterval(a, 1);

    return 0;
}