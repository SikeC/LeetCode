#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        vector<string> format;
        string tmp;
        int count;
        int n;
        n=numRows+numRows-2;
        if(!s.size()||!(numRows-1))
            return s;
        for(int i=0;i<numRows;i++)
            format.push_back(tmp);
        for(int i=0;i<s.length();i++)
        {
            count=i%n;
            if(count>numRows-1)
                count=(numRows-1)-(count-(numRows-1));
            format[count].push_back(s[i]);
        }
        for(int i=0;i<numRows;i++)
        {
            ret+=format[i];
        }
        return ret;
    }
};
int main()
{
    Solution s;
    string tmp="PHASIYIRPLIGAN";
    tmp=s.convert(tmp,5);
    return 0;
}