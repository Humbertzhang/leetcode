class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || (x!=0 && x%10==0))  //x < 0 Or x's tail is '0', x is not Palindrome Number
            return false;
        
        int sum = 0;

        while(x > sum)
        {
            sum = sum * 10 + x%10;
            x = x/10;
        }   //sum 根据奇数偶数不同有不同的情况

        return (x == sum) || (x == sum/10);
        // x == sum : even number
        // x == sum/10 : old number
    }
};
