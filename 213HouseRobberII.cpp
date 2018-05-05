/*
思路同I类似，但是因为围城圈，则应该计算1->n-1的和2->n的
之后取最大值
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        int dp1[n+1][2] = {0};
        int dp2[n+1][2] = {0};
        for(int i = 1; i <= n-1; i++){
            dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
            dp1[i][1] = dp1[i-1][0] + nums[i-1];
        }
        for(int i = 2; i <= n; i++){
            dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]);
            dp2[i][1] = dp2[i-1][0] + nums[i-1];
        }
        return max(max(dp1[n-1][0], dp1[n-1][1]), max(dp2[n][0], dp2[n][1]));
    }
};
