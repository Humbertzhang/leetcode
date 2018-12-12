"""
状态：numlist[i] 第i天的最高利润
状态转移方程：numlist[i] = max(numlist[i-1], prices[i] - minnum)
	      其中minnum是扫描到第i个价格的最低值
"""
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) <= 0:
            return 0
        minnum = prices[0]
        numlist = [0 for i in range(len(prices))]
        for i in range(len(numlist)):
            if prices[i] < minnum:
                minnum = prices[i]
            if i == 0:
                numlist[i] = 0
            else:
                numlist[i] = max(numlist[i-1], prices[i] - minnum)
        return numlist[-1]
