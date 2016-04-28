import sys

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        def roman_char_to_int(ch):
            return roman_char_to_int.roman_digit_table[ch]
        roman_char_to_int.roman_digit_table = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}

        res = 0
        previous_char = ''
        for ch in s:
            if ((ch == 'V' or ch =='X') and previous_char == 'I') or \
                    ((ch == 'L' or ch == 'C') and previous_char == 'X') or \
                    ((ch == 'D' or ch == 'M') and previous_char == 'C'):
                        res -= (roman_char_to_int(previous_char) * 2)

            previous_char = ch
            res += roman_char_to_int(ch)

        return res
        
solution = Solution()
print solution.romanToInt(sys.argv[1])
