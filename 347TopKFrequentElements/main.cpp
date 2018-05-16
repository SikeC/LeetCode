#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &l, const pair<int, int> &r)
  {
    return l.second > r.second;
  }

class Solution
{
public:
  
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    vector<pair<int, int> > fsort;
    map<int, int> frequent;
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
    {
      frequent[nums[i]]++;
    }
    for (map<int, int>::iterator it = frequent.begin(); it != frequent.end(); it++)
    {
      fsort.push_back(*it);
    }
    sort(fsort.begin(), fsort.end(), cmp);
    if(k>fsort.size())
      return ret;
    for(int i=0;i<k;i++)
    {
      ret.push_back(fsort[i].first);
    }
    return ret;
  }
};