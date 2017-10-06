/*6msSolution The fast*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return NULL;
        if(target > nums[nums.size()-1])
            return nums.size();
        if(target == nums[nums.size()-1])
            return nums.size()-1;
        for(int i = 0; i < nums.size();){
            if(nums[i] < target){
                if(nums[i+1] > target)
                    return i+1;
                else
                    i+=1;
            }
            else 
                return i;
        }
        
    }
};
