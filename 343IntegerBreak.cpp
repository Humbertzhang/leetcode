/*
状态：f(n) 即为正整数为n时的最大乘积
状态转移:
f(n) = max{ f(n-i) * max(f(i), i) }  1 <= i <= n-1
*/
class Solution {
public:
    int integerBreak(int n) {
        int dp[60] = {0};
        dp[1] = 1;
        int maxn = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                // 有可能 dp[i-j]还没有i-j本身大，此时用本身即可
                dp[i] = max(dp[i], max(dp[i-j], i-j) * j);
                maxn = max(maxn, dp[i]);
            }
        }
        return maxn;
    }
};
