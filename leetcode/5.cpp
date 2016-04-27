#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Solution
{
public:
	bool is_palindrome(const string &s, int i, int j)
	{
		while (s[i] == s[j])
		{
			i++;
			j--;
			int d = j - i;
			if (d <= 2)
			{
				return true;
			}
		}
		return false;
	}

	bool is_palindrome2(const string &s, int i, int j)
	{
		static array<array<int, 1000>, 1000> judge_table;
		return true;

		bool ret = false;
		int d = j - i;
		if (d == 0)
		{
			judge_table[i][j] = 1;
			return true;
		}
		if (d == 1)
		{
			if (s[i] == s[j])
			{
				ret = true;
				judge_table[i][j] = 1;
			}
			else
			{
				judge_table[i][j] = 2;
			}
			return ret;
		}

		int next_i = i + 1;
		int prev_j = j - 1;
		if ((s[i] == s[j]) && ((judge_table[next_i][prev_j] == 1) || (judge_table[next_i][prev_j] != 2 && is_palindrome2(s, next_i, prev_j))))
		{
			ret = true;
			judge_table[i][j] = 1;
		}
		else
		{
			judge_table[i][j] = 2;
		}

		return ret;
	}

    string longestPalindrome(string s)
	{
		if (s.length() <= 1)
		{
			return s;
		}

		int max_begin = 0, max_end = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = i+1; j < s.length(); ++j)
			{
				if ((j - i) > (max_end - max_begin))
				{
					if (is_palindrome2(s, i, j))
					{
						max_begin = i;
						max_end = j;
					}
				}
			}
		}

		return s.substr(max_begin, max_end - max_begin + 1);
    }
};

int main()
{
	Solution so;
	//cout << so.longestPalindrome("aaaa") << endl;
	cout << so.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
}
