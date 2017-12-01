/*Dynamic Programming
 *
 *Study from http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
 * */
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size() == 1){
            return s;
        }
        int start = 0, maxlen = 0;
        int size = s.size();
        bool table[size][size] = {0};
        //自己跟自己是回文
        for(int i = 0; i < size; i++){
            table[i][i] = true;
        }
        start = size - 1;
        maxlen = 1;
        //只有两个连在一起且是一样的才是长度为2的回文
        for(int i = 0; i < size - 1; i++){
            if(s[i] == s[i+1]){
                table[i][i+1] = true;
                start = i;
                maxlen = 2;
            }
        }
        //动态检查,如果table[i+1][j-1]是回文的，并且str[i] == str[j], 则table[i][j]也是回文的了
        for(int k = 3; k <= size; k++){
            for(int i = 0; i < size-k+1; i++){
                int j = i + k -1;
                if(table[i+1][j-1] && s[i] == s[j]){
                    table[i][j] = true;
                    if(k >  maxlen){
                        start = i;
                        maxlen = k;
                    }
                }
            }
        }
        string ret = s.substr(start, maxlen);
        return ret;
    }
};
