class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for(int i = 0; i < s.size(); ){
            if(s[i] >= g[count]){
                count += 1;
                i += 1;
                if(count == g.size()){
                    break;
                }
            }
            else {
                i += 1;
            }
        }
        return count;
    }
};
