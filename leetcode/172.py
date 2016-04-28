import sys
import math

#class Solution(object):
#	def trailingZeroes(self, n):
#		"""
#		:type n: int
#		:rtype: int
#		"""
#		trailing_zeros = 0
#		i = 1
#		while i <= n:
#			times, remains = self.num_consist(i, 10)
#			trailing_zeros += times
#			trailing_zeros += self.num_consist(remains, 5)[0]
#
#			i += 1
#		return trailing_zeros
#
#	def num_consist(self, n, num):
#		ret = 0
#		while n % num == 0:
#			n = n / num
#			ret += 1
#		return ret, n

#class Solution(object):
#	def trailingZeroes(self, n):
#		"""
#		:type n: int
#		:rtype: int
#		"""
#		trailing_zeros = 0
#		i = 5
#		while i <= n:
#			l = i
#			while l % 5 == 0:
#				l /= 5
#				trailing_zeros += 1
#
#			i += 5
#		return trailing_zeros

class Solution(object):
	def trailingZeroes(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		trailing_zeros = 0
		while n > 0:
			n = n / 5;
			trailing_zeros += n
		return trailing_zeros

solution = Solution()
print solution.trailingZeroes(int(sys.argv[1]))
