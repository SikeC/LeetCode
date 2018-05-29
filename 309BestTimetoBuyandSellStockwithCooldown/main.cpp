#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if(prices.size() ==0) return 0;  
        int len = prices.size();  
        vector<int> buy(len+1, 0), sell(len+1, 0);  
        buy[1] = -prices[0];  
        for(int i = 2; i <= len; i++)  
        {  
            buy[i] = max(sell[i-2]- prices[i-1], buy[i-1]);  
            sell[i] = max(sell[i-1], buy[i-1]+prices[i-1]);  
        }  
        return sell[len];  
        
    }
};
/*思路：一道有点诡异的动态规划．因为存在冷却时间

１．在第i天买一支股票还能剩下的利润＝第(i-2)天销售能够剩余的利润－第i天股票的价钱．

２．在第i天卖一支股票总的利润＝第(i-1)天买股票剩下的最大利润＋当前股票的价格．

也就是说需要维护两个状态的信息，一个是买股票所得到的剩余最大利润，一个是卖出股票之后得到的最大利润，他们互相依赖对方的信息．

再来进一步分析如何维持一个最大的利润．

对于买来说，当天是否买取决于买了之后是否比之前买所剩余的利润大，即状态转移方程为：

buy[i] = max(buy[i-1], sell[i-2] - prices[i-1]);

对于卖来说，同样当天是否将这只股票卖掉取决于卖掉能否获得更大的利润，状态转移方程为：

sell[i] = max(sell[i-1], sell[i-1] + prices[i-1]);*/