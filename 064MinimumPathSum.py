class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) is 0:
            return 0
        if len(grid[0]) is 0:
            return 0
        gw = len(grid[0])
        gh = len(grid)
        status = [[0]*gw for i in range(gh)]
        for i in range(len(status)):
            for j in range(len(status[0])):
                if i is 0 and j is 0:
                    status[i][j] = grid[0][0]
                elif i is 0:
                    status[i][j] = status[i][j-1] + grid[i][j]
                elif j is 0:
                    status[i][j] = status[i-1][j] + grid[i][j]
                else:
                    status[i][j] = min(status[i][j-1], status[i-1][j]) + grid[i][j]
        return status[gh-1][gw-1]
