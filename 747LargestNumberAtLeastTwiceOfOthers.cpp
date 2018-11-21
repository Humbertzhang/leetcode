class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > nums[maxi]) {
                maxi = i;
            }
        }
        int flag = 0;
        for(int i = 0; i < nums.size(); i++) {
            if( i == 0 ) {
                flag = 1;
            }
            if(i != maxi) {
                if(nums[maxi] - nums[i] < nums[i]) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag) {
            return maxi;
        }
        return -1;
    }
};
