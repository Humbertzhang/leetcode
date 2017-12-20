class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> numset;
        int size = nums.size();
        int sum = 0;
        for(int i = 0; i < size; i++){
            numset.insert(nums[i]);
            sum += nums[i];
        }
        int setsum = 0;
        for(std::set<int>::iterator it = numset.begin(); it != numset.end(); ++it){
            setsum += *it;
        }
        return 2*setsum - sum;
    }
};
