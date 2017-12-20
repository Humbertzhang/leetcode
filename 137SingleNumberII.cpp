class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<long long int> numset;
        int numsize = nums.size();
        long long int numsum = 0;
        for(int i = 0 ; i < numsize; i++){
            numset.insert(nums[i]);
            numsum += nums[i];
        }
        long long int setsum = 0;
        for(std::set<long long int>::iterator it = numset.begin(); it != numset.end(); ++it){
            setsum += *it;
        }
        return (setsum*3 - numsum)/2;
    }
};
