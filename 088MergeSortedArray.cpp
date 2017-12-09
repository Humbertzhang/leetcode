class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int pm, pn;
        for(pm = 0, pn = 0; pm < m && pn < n;){
            if(nums1[pm] >= nums2[pn]){
                nums.push_back(nums2[pn++]);
            }else{
                nums.push_back(nums1[pm++]);
            }
        }
        
        if(pm < m){
            for(int i = pm; i < m; i++){
                nums.push_back(nums1[i]);
            }
        }else if(pn < n){
            for(int i = pn; i < n; i++){
                nums.push_back(nums2[i]);
            }
        }
        nums1.assign(nums.begin(), nums.end());
    }
};
