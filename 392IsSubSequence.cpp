class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0){return true;}
        else if(t.size() == 0){return false;}
        int ssize = s.size();
        int tsize = t.size();
        int si = 0, ti = 0;
        while(true) {
            if(s[si] == t[ti]) {
                si += 1;
                ti += 1;
            }
            else {
                ti+=1;
            }
            
            if(si == ssize){
                return true;
            }
            else if(ti == tsize && si != ssize) {
                return false;
            }
        }
    }
};
