/*
O(n^4)算法2333不过一共9x9的格子倒也不怕
runtime beats 66.84% of cpp solution
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rawsize = board.size();
        int columnsize = board[0].size();
        //行
        for(int i = 0; i < rawsize; i++){
            bool appeared[10] = {0};
            for(int j = 0; j < columnsize; j++){
                if(board[i][j] >= '0' && board[i][j] <= '9'){
                    if(appeared[board[i][j] - '0']){
                        return false;
                    }
                    else{
                        appeared[board[i][j] - '0'] = true;
                    }
                }
            }
        }
        //列
        for(int j = 0; j < columnsize; j++){
            bool appeared[10] = {0};
            for(int i = 0; i < rawsize; i++){
                if(board[i][j] >= '0' && board[i][j] <= '9'){
                    if(appeared[board[i][j] - '0']){
                        return false;
                    }
                    else{
                        appeared[board[i][j] - '0'] = true;
                    }
                }
            }
        }
        //check每9个格子
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                bool appeared[10] = {0};         
                for(int ii = i; ii < i+3; ii++){
                    for(int jj = j; jj < j+3; jj++){
                        if(board[ii][jj] >= '1' && board[ii][jj] <= '9'){
                            if(appeared[board[ii][jj] - '0']){
                                return false;
                            }else{
                                appeared[board[ii][jj] - '0'] = true;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
