// 降价结束时候买进
// 升值结束的时卖出
// 贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1){
            return 0;
        }
        int profit = 0;
        int buy = 0;
        int buyprice = 0;
        for(int i = 0; i < size; i++){
            if(buy == 0){
                if(i == size-1 && prices[size-1] > prices[0]){
                    profit = prices[size-1] - prices[0];
                    continue;
                }
                if(prices[i] >= prices[i+1]){ continue; }
                else{
                    buyprice = prices[i];
                    buy = 1;
                }
            }
            else if(buy == 1){
                if(i == size-1 && prices[size-1] > buyprice){
                    profit += prices[size-1] - buyprice;
                    continue;
                }
                if(prices[i] <= prices[i+1]){ continue; }
                else{
                    profit += prices[i] - buyprice;
                    buyprice = prices[i+1];
                }
            }
        }
        return profit;
    }
};
