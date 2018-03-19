#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<string> strs = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    return vector<string>{};
}(); 

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = 0;;
        bool k = false;//标识位，最后一个单词开头字母，从后向前遍历就行
        for(i = s.length()-1; i >= 0; i--)
        {
            if(s[i] != ' ') k = true;
            if(s[i] == ' ' && k)
            {
                return count;
            }
            else if(s[i] != ' ')
            count ++;
        }
        return count;
    }
};

int main()
{
    return 0;
}