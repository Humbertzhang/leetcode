/*The most fast solution*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int slen = s.length();
        int ret = 0;
        int flag = 0;
        for(int i = slen - 1; i >=0; i--){
            if(s[i] == ' ' && flag == 0){
                continue;
            }else{
                if(flag == 1){
                    if(s[i] != ' '){
                        ret += 1;
                    }else{
                        break;
                    }
                }else{
                    flag = 1;
                    if(s[i] != ' '){
                        ret += 1;
                    }
                }
            }
        }
        return ret;
    }
};
