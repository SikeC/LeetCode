#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int i;
        int sum;
        map<char,int> RoToIn;
        RoToIn['I']=1;
        RoToIn['V']=5;
        RoToIn['X']=10;
        RoToIn['L']=50;
        RoToIn['C']=100;
        RoToIn['D']=500;
        RoToIn['M']=1000;
        sum = 0;
        if(s.size() == 1)
        {
            sum = RoToIn[s[0]];
            return sum;
        }
        for(i=0;i<s.size();i++)
        {
            if(RoToIn[s[i]]>=RoToIn[s[i+1]])
            {
                sum+=RoToIn[s[i]];
            }
            else
            {
                sum-=RoToIn[s[i]];
            }
        }
        return sum;
    }
};

int main(void)
{
    string R;
    Solution s;
    int x;
    R="DCXXI";
    x=s.romanToInt(R);
    cout<<x<<endl;
    return 0;
}