class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        ret.clear();
        int left = n;
        int right = n;
        string str = "";
        if(n != 0){
            generate(left, right, str);
        }
        return ret;
    }
    
    void generate(int left, int right, string str)
    {
        if(left == 0 && right == 0){
            ret.push_back(str);
            return;
        }
        if(left != 0){
            generate(left-1, right, str + '(');
        }
        if(right != 0 && left < right){
            generate(left, right-1, str + ')');
        }
    }
};
