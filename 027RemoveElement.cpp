/*2018-11-26
 *100%
 * */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = nums.size();
        if(count == 0) {
            return 0;
        }
        for(int i = 0; i < count; ) {
            if(nums[i] == val) {
                for(int j = i; j < nums.size()-1; j++) {
                    swap(nums[j], nums[j+1]);
                }
                count -= 1;
            }
            else {
                i += 1;
            }
        }
        return count;
    }
};

/*Your runtime beats 62.34 % of cpp submissions*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, count = 0;
        int size = nums.size();
        
        for(i = 0&&count; count < nums.size(); ++count){
            if(nums[i] == val){
                for(int j = i; j < nums.size() - 1; j++)
                    nums[j] = nums[j+1];
                size -= 1;
            }
            else
                i += 1;
        }
        return size;
    }
};
