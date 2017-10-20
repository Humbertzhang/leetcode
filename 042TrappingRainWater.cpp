class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1)
            return 0;
        
        int size = height.size();
        vector<int> leftmax(size), rightmax(size);
       	//leftmax跟rightmax为当前index的左边最大跟右边最大 
        leftmax[0] = height[0], rightmax[size-1] = height[size-1];
        int water = 0;
        
        for(int i = 1; i < size; i++){
            leftmax[i] = max(height[i], leftmax[i-1]);
        }
        for(int i = size-2; i >= 0; i--){
            rightmax[i] = max(height[i], rightmax[i+1]);
        }
        for(int i = 1; i < size-1; i++)
            water += (min(leftmax[i], rightmax[i]) - height[i]);
        
        return water;
    }
};
