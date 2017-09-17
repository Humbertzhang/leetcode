/*
每次跳跃1步，我们可跳跃步数减1．
如果新的位置步数大于剩余步数，使用新的步数继续移动．
如果可跳跃次数小于0并且还没到最后一个元素，那么失败。
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
            return true;
        int jump = nums[0];
        for(int i = 0; i < nums.size(); i++){
            jump -= 1;
            if(jump < 0)
                return false;
            jump = max(jump, nums[i]);
        }
        return true;
    }
};
