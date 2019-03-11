/*2018-11-25*/
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) {
            swap(a, b);
        }
        int asize = a.size();
        int bsize = b.size();
        if(asize == 0){
            return b;
        }
        else if(bsize == 0) {
            return a;
        }
        int ai = asize-1, bi = bsize-1;
        int bit = 0;
        string c = "";
        while(ai >= 0 || bi >= 0) {
            int m;
            if(bi >= 0){
                m = a[ai]-'0' + b[bi] - '0' + bit;
            } else {
                m = a[ai]-'0' + 0 + bit;
            }
            
            if(m == 3 || m == 2) {
                m -= 2;
                bit = 1;
            }
            else if(m == 1 || m == 0) {
                bit = 0;
            }
            c = to_string(m) + c;
            ai -= 1;
            bi -= 1;   
        }
        if(bit == 1) {
            c = to_string(1) + c;
        }
        return c;
        
    }
};


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
