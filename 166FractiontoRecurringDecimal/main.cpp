#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    string fractionToDecimal(int numerator, int denominator)  //说个实话，题不算太难，就判断余数是不是一样的，如果一样了就开始循环了，主要是各种条件蛋疼
    {
        string ret;
        int index;
        unordered_map<int, int> remaind;
        if (denominator == 0)
            return "";
        long long Intpart = (long long)numerator / (long long)denominator;
        long long Rempart = (long long)numerator % (long long)denominator;
        double ans=(double)numerator / (double)denominator;
        if(ans<0)
        {        
            ret+="-";
        }
        if(Intpart<0)
        {
            Intpart*=-1;
        }
        ret+=to_string(Intpart);
        if (Rempart == 0)
            return ret;
        ret.push_back('.');
        
        
        do
        {
            int index=ret.size();
            Rempart *= 10;
            if (remaind.find(Rempart) != remaind.end())
            {
                ret.insert(remaind[Rempart] , 1, '(');
                ret += ")";
                break;
            }
            int tmp = Rempart / denominator;
            if(tmp<0)
                tmp*=-1;
            ret+=to_string(tmp); 
            remaind[Rempart] = index;
            Rempart %= denominator;
            index++;
        } while (Rempart != 0);
        return ret;
    }
};

int main()
{
    return 0;
}