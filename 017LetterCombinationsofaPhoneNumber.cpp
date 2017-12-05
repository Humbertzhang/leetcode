/*slow than dfs solution*/
class Solution {
public:
    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    vector<string> letterCombinations(string digits) {
        ret.clear();
        int s_size = digits.size();
        int index = 0;
        string before = "";
        if(index < s_size){
            combine(digits, s_size, index, before);
        }
        return ret;
    }
    
    void combine(string digits, int s_size, int index, string before)
    {
        if(index == s_size){
            ret.push_back(before);
            return;
        }
        for(int i = 0; i < s[digits[index] - '0'].size(); i++){
            if(index < s_size){
                combine(digits, s_size, index+1, before + s[digits[index] - '0'][i]);
            }
        }
    }
};
