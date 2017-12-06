/*A Fucking slow method*/
class Solution {
public:
    vector<vector<string>> ret;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ret.clear();
        vector<string> strsorted = strs;
        map<string, bool> m;
        int ssize = strs.size();
        for(int i = 0; i < ssize; i++){
            sort(strsorted[i].begin(), strsorted[i].end());
        }
        for(int i = 0; i < ssize; i++){
            m[strs[i]] = false;
        }
        for(int i = 0; i < ssize; i++){
            if(!m[strs[i]]){
                vector<string> temp;
                for(int j = i; j < ssize; j++){
                    if(strsorted[i] == strsorted[j]){
                        temp.push_back(strs[j]);
                        m[strs[j]] = true;
                    }
                }
                if(!temp.empty()){
                    ret.push_back(temp);
                }
            }
        }
        return ret;
    }
    
};
