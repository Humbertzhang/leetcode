class NumArray {
public:
    vector<int> v;
    NumArray(vector<int> nums) {
        v.clear();
        int counter = 0;
        for(int i = 0; i < nums.size(); i += 1) {
            counter += nums[i];
            v.push_back(counter);
        }
    }
    
    int sumRange(int i, int j) {
        if(i == 0) {
            return v[j];
        }
        else {
            return v[j] - v[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
