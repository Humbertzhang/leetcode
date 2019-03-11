/*
类似找零钱
状态：f(n)即为完全平方数的个数
状态转移方程：
fn = min { f(n-第一个完全平方数)， f(n-第二个完全平方数), f(n-第三个完全平方数) .....}
直到 n - 完全平方数 不再 大于等于0
*/


class Solution {
public:
    int numSquares(int n) {
        int nums[n+1] = {0};
        vector<int> v;
        for(int i = 1; i <= n; i++) {
            int squ = i * i;
            if(squ <= n) {
                v.push_back(squ);
            }
            else {
                break;
            }
        }

        for(int i = 1; i <= n; i++) {
            // ti 为 f(i)的最小值
            int ti = i+1;
            for(int j = 0; j < v.size(); j++) {
                if(i >= v[j]) {
                    ti = min(ti, nums[i-v[j]] + 1);
                }
                else {
                    break;
                }
            }
            nums[i] = ti;
        }
        return nums[n];
    }
};
