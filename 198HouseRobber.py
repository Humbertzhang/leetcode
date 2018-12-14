"""
m[i] 到第i家可以偷的钱
m[i] = max(m[i-1]， m[i-2] + now)
"""
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 0:
            return 0
        elif len(nums) <= 2:
            return max(nums)
        m = [0 for i in range(len(nums))]
        m[0] = nums[0]
        m[1] = max(nums[0], nums[1])
        for i in range(len(nums)):
            if i >= 2:
                m[i] = max(m[i-1], m[i-2] + nums[i])
        return m[-1]
