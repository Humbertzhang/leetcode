class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 0){
            return 0;
        }
        int minp = prices[0];
        int profit = 0;
        for(int i = 0; i < size; i++){
            if(prices[i] < minp){
                minp = prices[i];
            }
            else if(prices[i] > minp){
                profit = max(prices[i] - minp, profit);
            }
        }
        return profit;
    }
};
