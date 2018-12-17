class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) is 0:
            return 0
        res = [[0]*len(t) for t in triangle]
        tlen = len(triangle)
        for i in range(len(triangle)):
            for j in range(len(triangle[i])):
                if i is 0 and j is 0:
                    res[i][j] = triangle[i][j]
                elif j is 0:
                    res[i][j] = res[i-1][j] + triangle[i][j]
                elif j is len(triangle[i])-1:
                    res[i][j] = res[i-1][j-1] + triangle[i][j]
                else:
                    res[i][j] = min(res[i-1][j-1], res[i-1][j]) +  triangle[i][j]
        minret = res[tlen-1][0]
        for it in res[tlen-1]:
            if it < minret:
                minret = it
        return minret
