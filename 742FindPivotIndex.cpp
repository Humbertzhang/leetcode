class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> numsrec;
        int rec = 0;
        for(int i = 0; i < nums.size(); i++) {
            rec = rec + nums[i];
            numsrec.push_back(rec);
        }
        for(int i = 0; i < numsrec.size(); i++) {
            // left == right
            if( numsrec[i] - nums[i] == rec - numsrec[i]) {
                return i;
            }
        }
        return -1;
    }
};
