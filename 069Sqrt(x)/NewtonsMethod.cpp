#include <iostream>
#include <math.h>
using namespace std;
static int x=[](){
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int mySqrt(int x) {
        double x0, x1,xx;
        if (x == 0)
            return 0;
        xx = x;
        x1 = xx / 2;
        do
        {
            x0=x1;
            x1=(x0+xx/x0)/2;      //X（n+1）=（Xn+a/Xn）/2
        }
        while(fabs(x0-x1)>0.999); // 精度
        return (int)x1;
    }
};
int main(void)
{
    Solution s;
    int a = 4;
    cout << s.mySqrt(4) << endl;
    return 0;
}