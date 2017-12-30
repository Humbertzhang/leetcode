class Solution {
public:
    bool isPalindrome(string s) {
        ::transform(s.begin(), s.end(), s.begin(), ::tolower);
        vector<char> real;
        real.reserve(1000);
        int strsize = s.size();
        for(int i = 0; i < strsize; i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
                real.push_back(s[i]);
            }
        }
        int vsize = real.size();
        for(int i = 0; i < vsize/2; i++){
            if(real[i] != real[vsize-1-i]){
                return false;
            }
        }
        return true;
    }
};
