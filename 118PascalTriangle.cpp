class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.reserve(100);
        
        for(int i = 0; i < numRows; i++){
            vector<int> linei;
            linei.reserve(100);
            
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    linei.push_back(1);
                }else{
                    linei.push_back(ret[i-1][j-1] + ret[i-1][j]);
                }
            }
            ret.push_back(linei);
        }
        return ret;
    }
};
