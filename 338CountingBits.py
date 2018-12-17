"""
		res[0] = 0
res[i] = 	res[i-1]+1    	# i为奇数
		res[i//2] 	# i为偶数
i为奇数时，i-1为偶数，其二进制组成最低位为0，所以i就是比i-1多了最低位这么一位1。而当i为偶数时，其二进制组成最低位为0，所以其1的位数就是除了最低位之外前面那一部分中1的位数，即是i/2中1的位数。		
"""
class Solution:
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        r = [0 for i in range(num+1)]
        for i in range(num+1):
            if i is 0:
                r[i] = 0
            else:
                # 偶数
                if i%2 is 0:
                    r[i] = r[i//2]
                # 奇数
                else:
                    r[i] = r[i-1] + 1  
        return r
