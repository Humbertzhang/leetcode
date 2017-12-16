/* 
The Second fast
You are here! 
Your runtime beats 24.06 % of cpp submissions.
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0){
            return "";
        }
        int i = 0, j = 0, end1 = 0, end2 = 0;
        while(1) {
            for(j = 0; j < size; j++) {
                if(strs[j][i] != strs[0][i] && strs[j][i] != '\0') {
                    end1 = 1;
                    break;
                }
                if(strs[j][i] == '\0') {
                    end2 = 1;
                    break;
                }
            }
            if(end1 || end2) {
                break;
            } else {
                i+=1;
            }
        }
        if (end2) {
            return strs[j];
        } else if (end1) {
            string ret = strs[j].substr(0, i);
            return ret;
        }
    }
};
