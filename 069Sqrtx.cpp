/*牛顿迭代法*/
class Solution {
public:
    int mySqrt(int x) {
        double delta = 0.00001;
        double num = x;
        while(fabs(pow(num, 2) - x) > delta){
            num = (num + x/num)/2;
        }
        return num;
    }
};
