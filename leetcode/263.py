import sys

class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        def remove_factor(num, factor):
            if num == 0:
                return num

            while num % factor == 0:
                num /= factor
            return num

        if remove_factor(remove_factor(remove_factor(num, 5), 3), 2) == 1:
            return True
        else:
            return False

solution = Solution()
print solution.isUgly(int(sys.argv[1]))
