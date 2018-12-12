class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        results = [i for i in range(n+1)]
        if n == 1 or n == 2:
            return results[n]
        else:
            for i in range(len(results)):
                if i >= 3:
                    results[i] = results[i-1] + results[i-2]
            return results[n]
