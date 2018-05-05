/*
DP
状态转移函数为
dp[i][0] = dp[i-1][1];  //不爬这个楼梯，则肯定爬其前一个了
dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + cost[i-1]; // 爬了这个楼梯，则可能爬了上一个可能没爬，所以取其最小再加上cost[i-1] (因为i是从1开始，而cost从0开始，故减1)
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1][2] = {0};
        for(int i = 1; i <= n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + cost[i-1];
        }
        return min(dp[n][0], dp[n][1]);
    }
};
