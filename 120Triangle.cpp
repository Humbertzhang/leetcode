// 动态规划思路
// 从下向上填表

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if(size <= 0){
            return 0;
        }
        if(size == 1){
            return triangle[0][0];
        }
        int table[size][size] = {0};
        for(int i = 0; i < size; i++){
            table[size-1][i] = triangle[size-1][i];
        }
        for(int j = size-2; j >= 0; j--){
            for(int k = 0; k < triangle[j].size(); k++){
                table[j][k] = min(table[j+1][k], table[j+1][k+1]) + triangle[j][k];
            }
        }
        return table[0][0];
    }
};
