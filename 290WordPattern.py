'''
这个题太适合用Python写了...所以用了Python
打败了95%的Python方法
'''
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split(' ')
        if(len(pattern) != len(words)):
            return False
        dic = {}
        for w in range(len(pattern)):
            if dic.get(pattern[w]) != None:
                if dic.get(pattern[w]) != words[w]:
                    return False
            else:
                dic[pattern[w]] = words[w]
        if len(set(dic.keys())) != len(set(words)):
            return False
        return True
