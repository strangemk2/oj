#include "leetcode.h"

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int sum = 0;
		while (n > 0)
		{
			if ((n % 2) == 1)
			{
				sum++;
			}
			n >>= 1;
		}
		return sum;
	}
};

int main()
{
	Solution so;
	cout << so.hammingWeight(1) << endl;
	cout << so.hammingWeight(11) << endl;
	cout << so.hammingWeight(232292) << endl;

	return 0;
}
