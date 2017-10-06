/*beats 12.8%*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
            return nums.size();
        int size = nums.size();
        for(int i = 0;i < size-1;){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin() + i+1);
                size-=1;
            }
            else
                i+=1;
        }
        return size;
    }
};
