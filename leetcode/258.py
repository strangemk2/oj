import sys

class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num < 10:
            return num

        sum = 0
        while num != 0:
            sum += num % 10
            num /= 10
        return self.addDigits(sum)

solution = Solution()
print solution.addDigits(int(sys.argv[1]))
