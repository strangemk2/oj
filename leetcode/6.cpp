#include "leetcode.h"

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (numRows <= 1)
		{
			return s;
		}

		string ret;
		for (int i = 0; i < numRows; ++i)
		{
			int index = i;
			while (index < s.length())
			{
				ret += s[index];
				if (i != 0 && i != numRows -1)
				{
					auto slash_index = index + (numRows - i - 1) * 2;
					if (slash_index < s.length())
					{
						ret += s[slash_index];
					}
				}
				index += ((numRows - 1) * 2);
			}
		}
		return ret;
	}
};

int main()
{
	Solution so;
	cout << so.convert("1234567890123456789012", 2) << endl;
}

// 1   9   7
// 2  80  68
// 3 7 1 5 9
// 46  24  0
// 5   3   1


