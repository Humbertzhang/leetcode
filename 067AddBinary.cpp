/*long but quick*/
class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        int flag = 0;
        string ret = "";
        int i,j;

        for(i = alen-1, j = blen-1; i>=0 || j>=0; i--, j--){
            int aint, bint;
            if(i >= 0){
                aint = a[i] - '0';
            }else{
                aint = 0;
            }
            if(j >= 0){
                bint = b[j] - '0';
            }else{
                bint = 0;
            }
            int sum = aint + bint + flag;
            
            if(sum == 0){
                ret += '0';
            }else if(sum == 1){
                ret += '1';
                flag = 0;
            }else if(sum == 2){
                ret += '0';
                flag = 1;
            }else if(sum == 3){
                ret += '1';
                flag = 1;
            }
        }
        if(flag == 1){
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
