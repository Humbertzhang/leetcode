/*62ms... Your runtime ONLY beats 17.55 % of cpp submissions.....T^T*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            bool appearred[256] = {0};
            int ulen = 0;
            for(int j = i; j < s.length(); j++){
                if(appearred[s[j] - ' ']){
                    int sub = s.substr(i, j - i).length();
                    ret = max(ret, sub);
                    break;
                }
                else{
                    appearred[s[j] - ' '] = true;
                    ulen += 1;
                    ret = max(ret, ulen);
                }
            }
        }
        return ret;
    }
};

/*First place solution in 9ms*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int place[255];
        fill(place, place + 255, -1);
        int start = 0;
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            if(place[s[i]] >= start){
                result = max(result, i - start);
                start = place[s[i]] + 1;
            }
            place[s[i]] = i;
        }
        return max(result, int(s.size()) - start);
    }
};
