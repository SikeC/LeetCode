#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(const Interval &l,Interval &r)
{
    return l.start<r.start;
}

class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        Interval tmp;
        vector<Interval> ret;
        if(!intervals.size())
            return intervals;

        sort(intervals.begin(),intervals.end(),cmp);
        
        tmp.start=intervals[0].start;
        tmp.end=intervals[0].end;

        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start<=tmp.end)
            {
                if(tmp.end<intervals[i].end)
                    tmp.end=intervals[i].end;
            }
            else
            {
                ret.push_back(tmp);
                tmp.start=intervals[i].start;
                tmp.end=intervals[i].end;
            }
        }
        ret.push_back(tmp);
        return ret;
    }
};