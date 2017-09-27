/*
		Wrong Answer
		仅仅求正序与反序的最长公共子串不行
        求两个字符串的最长公共子串
        字符串s, s2.
        判断s[i]为起点的各个子串在b中是否能找到相同子串
        如果能的话看看是不是sret小，如果是，temp子串替换sret.
        i的值递增.
        注意有s2.find()这种用法
        有reverse(begin, end)这种写法
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        string sret;
        
        if(s.size() > s2.size())
            swap(s, s2);
        
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j ++ ){
                string temp = s.substr(i, j-i+1);
                if(int(s2.find(temp)) < 0) //s2中找不到相同字符串
                    break;
                else if(sret.size() < temp.size())
                    sret = temp;
            }
        }
        return sret;
    }
};
