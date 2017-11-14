/*
朴素算法的字符串模式匹配，时长6ms
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle[0] == '\0' && haystack[0] == '\0') {
            return 0;
        } else if (haystack[0] == '\0') {
            return -1;
        } else if (needle[0] == '\0') {
            return 0;
        }
        
        int i = 0, j = 0;
        while(haystack[i+j] != '\0' && needle[j] != '\0') {
            if(haystack[i+j] == needle[j]) {
                j++;
            } else {
                i++;
                j = 0;
            }
            if(needle[j] == '\0')
                return i;
        }
        return -1;
    }
};
