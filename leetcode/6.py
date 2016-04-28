import sys

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        def cal_pos(x, y, n):
            if y == 0 or y == n-1:
                return y + (2 * n - 2) * x
            else:
                mod = x % 2
                x = x / 2
                if mod == 0:
                    return y + (2 * n - 2) * x
                else:
                    x += 1
                    return y + (2 * n - 2) * x - y * 2

        ret = ""

        if len(s) <= numRows or numRows == 1:
            return s

        for y in range(numRows):
            x = 0
            pos = cal_pos(x, y, numRows)
            while pos < len(s):
                ret += s[pos]
                x += 1
                pos = cal_pos(x, y, numRows)
        return ret


solution = Solution()
print solution.convert("PAYPALISHIRING", 2)
#
#P     I     N
#A   L S   I G
#Y A   H R
#P     I
#
#PINALSIGYAHRPI
#
#1,             1+(2n-2),               1+(2n-2)*2...
#2, 2+(2n-2)-2, 2+(2n-2), 2+(2n-2)*2-2, 2+(2n-2)*2
#3, 3+(2n-2)-4, 3+(2n-2), 3+(2n-2)*2-4, 3+(2n-2)*2
#4, 4+(2n-2)-6, 4+(2n-2), 4+(2n-2)*2-6, 4+(2n-2)*2
#...
#n,             n+(2n-2),               n+(2n-2)*2
#
#
#1     7     3
#2   6 8   2 4
#3 5   9 1
#4     0
#
#
#y + (2n-2) * x

#print cal_pos(int(sys.argv[1]), int(sys.argv[2]), 4)
