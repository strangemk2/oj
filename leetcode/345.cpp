#include "leetcode.h"
#include <algorithm>

class Solution {
public:
	bool is_vowel(char c)
	{
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
				c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	}

	long find_next_vowels(const string &s, long current)
	{
		long i;
		for (i = current + 1; i < s.length(); i++)
		{
			if (is_vowel(s[i]))
			{
				break;
			}
		}
		return i;
	}

	long find_prev_vowels(const string &s, long current)
	{
		long i;
		for (i = current - 1; i >= 0; i--)
		{
			if (is_vowel(s[i]))
			{
				break;
			}
		}
		return i;
	}

    string reverseVowels(string s) {
		if (s.length() == 0) return s;

		long f = find_next_vowels(s, -1);
		long b = find_prev_vowels(s, s.length());

		while (f < b)
		{
			swap(s[f], s[b]);
			f = find_next_vowels(s, f);
			b = find_prev_vowels(s, b);
		}

		return s;
    }
};

int main()
{
	Solution so;
	cout << so.reverseVowels("") << endl;
	cout << so.reverseVowels("1") << endl;
	cout << so.reverseVowels("a") << endl;
	cout << so.reverseVowels("aA") << endl;
	cout << so.reverseVowels("aeiou") << endl;
	cout << so.reverseVowels("hello") << endl;
	cout << so.reverseVowels("leetcode") << endl;
}
