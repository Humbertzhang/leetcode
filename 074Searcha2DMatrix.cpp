/*
9ms Solution
The second fast Solution
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        int msize = matrix.size();
        int emptyflag = 0;
        for(int i = 0; i < msize; i++){
            if(!matrix[i].empty()){
                emptyflag = 1;
                break;
            }
        }
        if(emptyflag == 0){
            return false;
        }
        
        for(int i = 0; i < msize; i++){
            int mmsize = matrix[i].size();
            if(target <= matrix[i][mmsize-1] || i == 0){
                for(int j = 0; j < mmsize; j++){
                    if(matrix[i][j] == target){
                        return true;
                    }
                }
                if(i != 0){
                    return false;
                }
            }
        }
        return false;
    }
};
