/*
动态规划思想的最长递增子序列
动态规划函数: d(i) = max{1, d(j)}, j < i;
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0){
            return 0;
        }
        int d[n] = {0};
        int maxlen = 1;
        for(int i = 0; i < n; i++){
            d[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && d[j]+1 > d[i]){
                    d[i] = d[j]+1;
                }
            }
            if(d[i] > maxlen){
                maxlen = d[i];
            }
        }
        return maxlen;
    }
};
