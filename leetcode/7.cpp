#include "leetcode.h"

class Solution
{
public:
	int reverse(int x)
	{
		bool minus_flag = false;
		if (x < 0)
		{
			minus_flag = true;
		}

		x = abs(x);

		int ret = 0;
		while (x > 0)
		{
			long long next = (static_cast<long long>(ret) * 10) + (x % 10);
			ret = next;
			if (ret != next)
			{
				return 0;
			}
			x /= 10;
		}
		return minus_flag?-ret:ret;
	}
};

int main()
{
	int x = -2147483412;
	//int x = 1534236469;
	Solution so;
	cout << so.reverse(x) << endl;
}
