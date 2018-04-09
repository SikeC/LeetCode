#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> hash;
        vector<int> res;
        int findnum;
        for (int i = 0; i < numbers.size(); i++)
        {
            findnum = target - numbers[i];
            if (hash.find(findnum) != hash.end())
            {
                res.push_back(hash[findnum] + 1);
                res.push_back(i + 1);
            }
            hash[numbers[i]] = i;
        }
        return res;
    }
};

int main()
{

    return 0;
}