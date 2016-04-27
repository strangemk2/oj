//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Solution
{
public:
	int count_letter(const string &s)
	{
		array<int, 256> window;
		for (auto &n : window) n = 0;

		for (auto c : s)
		{
			window[c]++;
		}

		int ret = 0;
		for (auto &n : window)
		{
			if (n == 1)
			{
				ret++;
			}
			else if (n > 1)
			{
				return 0;
			}
		}
		return ret;
	}

    int lengthOfLongestSubstring(string s)
	{
		if (s.length() == 0)
		{
			return 0;
		}

		int f = 0;
		int b = 1;
		int ret = 0;

		while (b <= s.length() && f < b)
		{
			cout << s;
			auto l = count_letter(s.substr(f, b-f));
			if (l != 0)
			{
				b++;
				if (l > ret)
				{
					ret = l;
				}
			}
			else
			{
				f++;
			}
		}

		return ret;
    }
};

int main()
{
	string s = "c";
	Solution so;
	cout << so.lengthOfLongestSubstring(s) << endl;

	return 0;
}
