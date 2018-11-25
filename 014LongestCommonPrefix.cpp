/*
 * 2018-11-25
 * */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = 0;
        int minsize = INT_MAX;
        if(strs.size() == 0){
            return "";
        }
        for(int i = 0; i < strs.size(); i++) {
            minsize = min(minsize, int(strs[i].length()));
        }
        int i;
        for(i = 0; i < minsize; i++) {
            int flag = 1;
            char c = strs[0][i];
            for(int j = 0; j < strs.size(); j++) {
                if(c != strs[j][i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        if(i == 0) {
            return "";
        }
        return strs[0].substr(0, i);
    }
};

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
