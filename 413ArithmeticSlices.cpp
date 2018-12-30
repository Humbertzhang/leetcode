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

/*
 *注意此处的dp[i]记录的为增加了最后数字所增加的增量
 * */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        // 如果 1 2 3 4 为等差数列了，[1,2,3,4,5]只比[1,2,3,4]多了一个元素【5】，在不包括[1,2,3,4]的前提下，多了[2,3,4,5]这个等差数列的数量为3（等于[1,2,3,4]的数量，为3），还有[1,2,3,4,5]这个本身的数量。
        // 所以如果A[i] - A[i-1] == A[i-1]-A[i-2], 则dp[i] = dp[i-1] + 1. 此处的dp[i]为增加了5这个数字造成的**增量**.
        if(A.size() <= 2) {
            return 0;
        }
        int dp[A.size()] = {0};
        for(int i = 2; i < A.size(); i++) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
                dp[i] = dp[i-1] + 1;
            }
        }
        int sum = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += dp[i];
        }
        return sum;
    }
};
