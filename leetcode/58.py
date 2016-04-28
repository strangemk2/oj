import sys

class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s_len = len(s)
        if s_len == 0:
            return 0

        end = -1
        while end >= -s_len and s[end] == ' ':
            end -= 1
        end = -end

        start = -end
        while start >= -s_len:
            if s[start] == ' ':
                return (-start) - end
            start -= 1
        return s_len - end + 1

solution = Solution()
print solution.lengthOfLastWord(sys.argv[1])
