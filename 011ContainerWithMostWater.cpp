/*
之前用了O(n^2)的写法，超时了
看了Article,算法是一开始有两个pointer指向最前面与最后面,
然后算面积,之后将两条线中比较短的那一条的一端的pointer
向里面移一个，再次计算面积.
如果移动较长的那一条，因为较短的那一条才决定了面积的大小,所以一定不会
有任何增加，而如果移动较短那一条就可能因为里面又变长了而使面积变大.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = 0, v = 0;
        int i = 0,j = height.size()-1;
        while(i!=j){
            int vtemp = min(height[i], height[j])*(j-i);
            if(vtemp > v){
                v = vtemp;
            }
            if(height[i] < height[j])
                i+=1;
            else
                j-=1;
        }
        return v;
    }
};
