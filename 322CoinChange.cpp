class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int mins[amount + 1];
        for(int i = 0; i < amount+1; i++) {
            mins[i] = amount+1;
        }
        mins[0] = 0;
        for(int i = 0; i < amount+1; i++){
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0 && mins[i-coins[j]] + 1 < mins[i]) {
                    mins[i] = mins[i-coins[j]] + 1;
                }
            }
        }
        if(mins[amount] == amount+1) {
            return -1;
        }
        return mins[amount];
    }
};
