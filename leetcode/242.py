import sys

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def sort_word(word):
            l = list(word)
            l.sort()
            return "".join(l)
        return sort_word(s) == sort_word(t)


solution = Solution()
print solution.isAnagram("anagram", "nagaram")
print solution.isAnagram("rat", "car")
