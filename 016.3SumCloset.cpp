/*
最开始将nums数组排序,以便后续的操作.
先将前三个加起来作为初始比较值(ret)。
之后，对于整个数组循环。
循环中首先选出一个i,
之后以i+1为j, 以n-1为k.
将sum = nums[i] + nums[j] + nums[k]作为3sum, 将其与target的差值的绝对值
和ret与target插值的绝对值相比较，若其差值的绝对值小于ret差值的绝对值
则将其作为下一个ret.
（此处检查是否就等于target, 若等于直接返回）
接下来判断sum 与 target的大小关系
若sum < target, 则需要sum增加，因此j+=1(因为nums已经排过序了)
若 > , 则 k -= 1, 一直循环到j不大于k,则继续下一轮i的循环
*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int vsize = nums.size();
        if(vsize <= 3){
            return accumulate(nums.begin(), nums.end(), 0);
        }
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        int sum = 0;
        for(int i = 0; i < vsize; i++){
            int j = i+1;
            int k = vsize-1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < abs(ret - target)){
                    ret = sum;
                    if(ret == target){
                        return target;
                    }
                }
                if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ret;
    }
};
