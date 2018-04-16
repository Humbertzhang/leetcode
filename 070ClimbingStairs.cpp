class Solution {
public:
    // 用于记录已经算过的数值，避免重复计算
    int a[1000];

    int climbStairs(int n) {
        if(n <= 2)
            return n;
        
        int nmin1 = 0;
        int nmin2 = 0;
        if(a[n-1] != 0){
            nmin1 = a[n-1];
        }else{
            nmin1 = climbStairs(n-1);
            a[n-1] = nmin1;
        }
        if(a[n-2] != 0){
            nmin2 = a[n-2];
        }else{
            nmin2 = climbStairs(n-2);
            a[n-2] = nmin2;
        }
        
        return nmin1 + nmin2;
    }
};
