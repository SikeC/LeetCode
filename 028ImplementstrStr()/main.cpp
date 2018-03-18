#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
  public:
    int strStr(string haystack, string needle)
    /*{ //用Knuth-Morris-Pratt匹配模式的算法思想，计算所needle的所有公有前缀数存放到数组中
        //如果匹配到了前三个，那么下一次就应该跳转到哪个去 移动位数 = 已匹配的字符数 - 对应的部分匹配值
        int next[needle.length()];
        int j = 0;
        int k = -1;
        if (haystack.length() == 0 || needle.length() == 0)
        {
            return -1;
        }

        next[0] = -1;

        // 根据已知的前j位推测第j+1位
        while (j < needle.length())
        {
            if (k == -1 || needle[j] == needle[k])
            {
                // 如果needle[j + 1] == needle[k + 1]，回退后仍然失配，所以要继续回退
                if (needle[j + 1] == needle[k + 1])
                {
                    next[++j] = next[++k];
                }
                else
                {
                    next[++j] = ++k;
                }
            }
            else
            {
                k = next[k];
            }
        }
        for (int i = 0; i < haystack.length(); i++)
        {
            while (k > -1 && needle[k + 1] != haystack[i]) //needle和haystack不匹配，且k>-1（表示needle和haystack有部分匹配）
                k = next[k];                               //往前回溯
            if (needle[k + 1] == haystack[i])
                k = k + 1;
            if (k == needle.length()) //说明k移动到needle的最末端
            {
                //cout << "在位置" << i-needle.length()<< endl;
                //k = -1;//重新初始化，寻找下一个
                //i = i - needle.length();//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠）
                return i - needle.length(); //返回相应的位置
            }
        }
        return -1;
    }*/
    /*{
        char *buf;
        buf = strstr(haystack.c_str(),needle.c_str());

        return haystack.find(buf,0);
    }*/
    {
        int nsize = needle.size();
        int hsize = haystack.size();
        if (nsize == 0)
            return 0;
        int *table = new int[nsize];
        memset(table, 0, sizeof(int) * nsize);
        //building match table
        for (int i = 1, j = 0; i < nsize - 1;)
        {
            if (needle[i] != needle[j])
            {
                if (j > 0)
                {
                    j = table[j - 1];
                }
                else
                {
                    i++;
                }
            }
            else
            {
                table[i] = j + 1;
                i++;
                j++;
            }
        }
        //matching
        for (int i = 0, match_pos = 0; i < hsize;)
        {
            if (haystack[i] == needle[match_pos])
            {
                if (match_pos == nsize - 1)
                {
                    return i - (nsize - 1);
                }
                else
                {
                    i++;
                    match_pos++;
                }
            }
            else
            {
                if (match_pos == 0)
                {
                    i++;
                }
                else
                {
                    match_pos = table[match_pos - 1];
                }
            }
        }
        delete[] table;
        return -1;
    }
};

int main(void)
{
    string str = "hello";
    string tmp = "ll";
    Solution s;
    int ret;
    ret = s.strStr(str, tmp);
    cout << "hello" << ret << endl;
    return 0;
}