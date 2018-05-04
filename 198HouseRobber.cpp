/*
dp[i][1]代表取第i个的时候的最大值
dp[i][0]代表不取时最大值
dp的i从1开始算则
dp[i][1] = dp[i-1][0] + nums[i-1]   // 如果i取了则它前面的不应该拿
dp[i][0] = max(dp[i-1][0], dp[i-1][1])  // 如果i没取，则其最大值等于他前面的取或者不取的最大值
return max(dp[n][0], dp[n][1])
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0){
            return 0;
        }
        int dp[n+1][2] = {0};
        for(int i = 1; i <= n; i++){
            dp[i][1] = dp[i-1][0] + nums[i-1];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[n][1], dp[n][0]);
    }
};
