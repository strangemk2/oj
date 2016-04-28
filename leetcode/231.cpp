#include "leetcode.h"

class Solution
{
public:
	bool isPowerOfTwo(int n)
	{
		int power = 1;
		for (int i = 0; i < 32 && power <= n; i++)
		{
			if (power == n)
			{
				return true;
			}
			else
			{
				power <<= 1;
			}
		}
		return false;
	}
};

int main()
{
	Solution so;
	cout << so.isPowerOfTwo(1) << endl;
	cout << so.isPowerOfTwo(0) << endl;
	cout << so.isPowerOfTwo(4) << endl;
	cout << so.isPowerOfTwo(5) << endl;
	cout << so.isPowerOfTwo(4096) << endl;
	cout << so.isPowerOfTwo(32) << endl;

	return 0;
}
