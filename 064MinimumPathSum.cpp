// 用动态规划的思想来解决

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m <= 0){
            return 0;
        }
        int n = grid[0].size();
        if(n <= 0){
            return 0;
        }
        int count[m][n] = {0};
        count[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            count[i][0] = grid[i][0] + count[i-1][0];
        }
        for(int j = 1; j < n; j++){
            count[0][j] = grid[0][j] + count[0][j-1];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                count[i][j] = min(count[i-1][j], count[i][j-1]) + grid[i][j];
            }
        }
        return count[m-1][n-1];
    }
};

// 递归思路来解决，只能通过24个样例，之后会爆时间
// 问题在于对于同一个块计算多次，只要路径上有该块就会计算一次
// 而动态规划法只计算一次
class Solution {
public:
    int min = 65535;
    int m = 0;
    int n = 0;
    
    int minPathSum(vector<vector<int>>& grid) {
        int rcd = 0;
        
        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();
        if(n == 0)
            return 0;
        
        findpath(grid, 0, 0, rcd);
        return min;
    }
    void findpath(vector<vector<int>>& grid, int h, int l, int rcd){
        if(h == m-1 && l == n-1){
            if(rcd + grid[h][l] < min){
                min = rcd + grid[h][l];
            }
        }
        // 向下
        if(h < m-1){
            findpath(grid, h+1, l, rcd + grid[h][l]);
        }
        // 向右
        if(l < n-1){
            findpath(grid, h, l+1, rcd + grid[h][l]);
        }
    }
};
