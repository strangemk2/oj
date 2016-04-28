#include "leetcode.h"

class Solution {
public:
	int titleToNumber(string s)
	{
		int ret = 0;
		for (auto ch : s)
		{
			ret *= 26;
			ret += (ch - 'A' + 1);
		}
		return ret;
	}
};

int main()
{
	Solution so;
	cout << so.titleToNumber("ZZ") << endl;
}
