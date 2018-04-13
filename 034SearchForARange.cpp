/*
自己想的方法，只超过了百分之10
大概思路是用二分法找到一个等于target的位置
之后用从target的位置往前找直到不是该数
再往后找直到不是该数
就可以得到结果了
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        if(end == 0){
            return returnfunc(-1, -1);
        }
        int index = bsearch(start, end, target, nums);
        if(index == -1){
            return returnfunc(-1, -1);
        }
        
        int s = index;
        int e = index;
        while(nums[s] == target && s >= 0){
            s-=1;
        }
        while(nums[e] == target && e <= end){
            e += 1;
        }
        return returnfunc(s+1, e-1);
    }
    
    int bsearch(int start, int end, int target, vector<int>& nums) {
        int mid = (start + end)/2;
        if(nums[mid] < target){
            if((mid + end)/2 != mid)
                return bsearch(mid, end, target, nums);
            else
                return -1;
        }
        else if(nums[mid] > target) {
            if((mid+start)/2 != mid)
                return bsearch(start, mid, target, nums);
            else
                return -1;
        }
        else if(nums[mid] == target) {
            return mid;
        }
        
    }
    
    vector<int> returnfunc(int a, int b){
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};
