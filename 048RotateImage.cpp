/*
先沿反对角线交换
再沿中间线交换
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //沿反对角线交换
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (n-i); j++){
                if(i+j != n-1){
                    swap(matrix[i][j], matrix[n-j-1][n-i-1]);
                }
            }
        }

        //沿中间线交换
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
    }
};
