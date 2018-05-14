/*
数组数
dp[i] = dp[i-1] + 1
Approach #5:https://leetcode.com/articles/arithmetic-slices/
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int asize = A.size();
        if(asize < 3){
            return 0;
        }
        int sum = 0;
        int dp[asize] = {0};
        for(int i = 2; i < asize; i++){
            int j = i-2;
            if(A[j+1] - A[j] != A[j+2] - A[j+1]) {
                dp[i] = 0;
            }else{
                dp[i] = dp[i-1] + 1;
                sum += dp[i];
            }
        }
        return sum;
    }
};
