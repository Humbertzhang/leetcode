/*
关于本题中的回文字符串的扫描：
对每一个字符，从其左右开始延伸，判断其left和right是否一样，如果一样则继续left-=1 right+=1，知道left或者right有一个到达边界.
注意要考虑到奇数和偶数回文字符串两种情况。
一个是从i-1 i+1开始左右扫描，一个是从i,i+1开始左右扫描
*/
class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        int left, right;
        for(int i = 0; i < s.length(); i++) {
            // 字符本身
            ret += 1;
            // 针对奇数长度的字符串扫描
            left = i-1; right = i+1;
            while(left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
                    ret += 1;
                    left -= 1;
                    right += 1;
                } else {
                    break;
                }
            }
            // 针对偶数长度的字符串扫描
            left = i; right = i+1;
            while(left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
                    ret += 1;
                    left -= 1;
                    right += 1;
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};
