class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
		/*record数组记录下到达每个节点的累加数值，避免重复计算区间数值大小*/
        int record[nums.size()] = {0};
        int start = 0, end = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0){record[i] = nums[i];}
            else{
                record[i] = record[i-1] + nums[i];
            }
        }
		/*总数值小于s则return 0*/
        if(record[nums.size()-1] < s) {
            return 0;
        }
        int minr = nums.size();
		/*
		 * 由0,0开始往后扫描，会将所有会出现的组合扫描到
		 * */
        while(true) {
            if(end > nums.size()-1 || start > nums.size()-1 || end < start) {break;} 
            int sum = record[end] - record[start] + nums[start];
            if(sum < s) {
                end += 1;
            }
            else {
                minr = min(minr, end - start + 1); 
                start += 1;
            }
            
        }
        return minr;
    }
};
