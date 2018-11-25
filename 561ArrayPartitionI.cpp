class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 0;
        for(int i = 0; i < nums.size()-1; i+=2){
            n += nums[i];
        }
        return n;
    }
};
