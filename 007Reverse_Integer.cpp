class Solution {
public:
    int reverse(int x) {
        int flag = 0;// 1 is 正数 -1 is 负数
        
        if(x<0){
            flag = -1;
            x = -x;
        }
        else{
            flag = 1;
        }
        
        int rst = 0;
        int temp = 0;

        while(x > 0){
            temp = rst * flag;
            if (temp > INT_MAX /10 || temp < INT_MIN /10)
                return 0;
            rst *= 10;
            rst += x%10;
            x = x/10;
        }

        return flag * rst;
    }
};
