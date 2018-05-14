/*
每次检查自己的上一个数的尾数为1的个数
dp[i] = dp[i-1] - 尾数1个数 + 1
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<bitset<32>> v;
        v.reserve(num+1);
        for(int i = 0; i < num; i++) {
            bitset<32> bs32(i);
            v.push_back(bs32);
        }
        vector<int> dp(num+1, 0);
        
        for(int i = 1; i <= num; i++){
            if(v[i-1][0] == 0){
                dp[i] = dp[i-1] + 1;
            }
            int tail1 = 0;
            for(int j = 0; j < 32; j++){
                if(v[i-1][j] == 1){
                    tail1 += 1;
                }else{
                    break;
                }
            }
            dp[i] = dp[i-1] - tail1 + 1;
        }
        return dp;
    }
};
