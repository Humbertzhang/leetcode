class Solution {
public:
    int a[101][101];
    int Asize;
    int minFallingPathSum(vector<vector<int>>& A) {
        // clear a
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                a[i][j] = 0;
            }
        }
        Asize = A.size();
        // 填充第一层
        for(int i = 0; i < Asize; i++) {
            a[0][i] = A[0][i];
        }
        // 递归向上填
        // i为行  j为列
        for(int i = 1; i < Asize; i++) {
            for(int j = 0; j < Asize; j++) { 
                //fill a[i][j]
                int minl = a[i-1][j];
                for(int m = j-1; m <= j+1; m++) {
                    if(m >= 0 && m < Asize) {
                        if(a[i-1][m] < minl) {
                            minl = a[i-1][m];
                        }
                    }
                }
                a[i][j] = A[i][j] + minl;
            }
        }
        // 在最后一层中找到最小的
        int ret = a[Asize-1][0];
        for(int i = 0; i < Asize; i++) {
            if(a[Asize-1][i] < ret) {
                ret = a[Asize-1][i];
            }
        }
        return ret;
    }
    // fill a[row][column]
    // a[r][c] = min{ a[row-1][column-1] a[row-1][column] a[row-1][column+1] } + A[r][c]
};
