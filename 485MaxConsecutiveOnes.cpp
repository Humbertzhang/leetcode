class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                int counttmp = 0;
                for(int j = i; j < nums.size(); j++) {
                    if(nums[j] == 1) {
                        counttmp += 1;
                    } else {
                        break;
                    }
                    i = j;
                }
                count = max(count, counttmp);
            }
        }
        return count;
    }
};
