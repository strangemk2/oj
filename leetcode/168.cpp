#include "leetcode.h"

class Solution {
public:
	string convertToTitle(int n)
	{
		string ret;
		while (n > 0)
		{
			auto mod = n % 26;
			n /= 26;
			if (mod == 0)
			{
				ret = 'Z' + ret;
				n--;
			}
			else
			{
				ret = static_cast<char>(mod + 'A' - 1) + ret;
			}
		}
		return ret;
	}
};

int main()
{
	Solution so;
	cout << so.convertToTitle(26) << endl;
	cout << so.convertToTitle(702) << endl;
	cout << so.convertToTitle(703) << endl;
	cout << so.convertToTitle(1) << endl;
	cout << so.convertToTitle(19392) << endl;
	cout << so.convertToTitle(392) << endl;
}
