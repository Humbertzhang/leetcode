class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.size()-1;
        for(int i = 0; i < s.size()/2;) {
            swap(s[i], s[j]);
            i += 1;
            j -= 1;
        }
        return s;
    }
};
