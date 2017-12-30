class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ret;
        ret.reserve(100);
        for(int i = 0; i <= rowIndex; i++){
            vector<int> line;
            line.reserve(100);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    line.push_back(1);
                }else{
                    line.push_back(ret[i-1][j-1] + ret[i-1][j]);
                }
            }
            ret.push_back(line);
        }
        return  ret[rowIndex];
    }
};
