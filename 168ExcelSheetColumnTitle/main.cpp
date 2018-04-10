#include <iostream>
#include<algorithm>
#include <string>
using namespace std;   //用进制转换的思想
class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        int i=0;
        while (n)
        {
            n--;
            i = n % 26;
            ret.push_back('A'+i);
            n = n / 26;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};