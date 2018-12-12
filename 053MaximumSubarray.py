class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 0:
            return 0
        # 这里有个不清楚的地方，当序列中都为负数时，该是0还是最小的负数呢？
        # 题目是用的最小的负数。
        maxsum = nums[0]
        maxindex = nums[0]
        for n in nums[1:]:
            # 前面的和小于0时，就算当前为负数，最小也是加上这个负数，而不是0.
            # 状态转移方程：sum[i]=max(sum[i-1]+a[i],a[i])
            if maxindex <= 0:
                maxindex = n
            else:
                maxindex += n
            if maxindex > maxsum:
                maxsum = maxindex
        return maxsum
