/*
You make profit by buying low and selling high, so a person would buy at trough and sell at crest, here the subtle thing is it is equivalent to buying at i and selling at i + 1 as long as price is increasing, this is fine because you can do as many transactions as you want.

Suppose the prices are

1  2  3  4  5
then 5 - 1 == 2 - 1 + 3 - 2 + 4 - 3 + 5 - 4
即，你每次只要一上升就卖所获得的收益和这一段的最大减去最小是一样的
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int ret = 0;
        
        for(int i = 1; i < prices.size(); i++)
            if(prices[i] > prices[i-1])
                ret += (prices[i] - prices[i-1]);
        
        return ret;
    }
};
