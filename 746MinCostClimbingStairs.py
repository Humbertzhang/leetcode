"""
状态:sumcost[i]
转移方程: sumcost[i] = min(cost[i-2], cost[i-1]) + cost[i]
需要注意的是该题目的顶是一个消耗为0的楼梯级,与一般情况不一样
"""
class Solution:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        cost.append(0)
        top = len(cost)
        sumcost = [i for i in cost]
        sci = 2
        while sci < top:
            sumcost[sci] = min(sumcost[sci-2], sumcost[sci-1]) + cost[sci]
            sci = sci + 1
        return sumcost[-1]


