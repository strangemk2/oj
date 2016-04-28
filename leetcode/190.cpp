#include "leetcode.h"

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		int reversed = 0;
		for (size_t i = 0; i < sizeof(n) * 8; ++i)
		{
			reversed <<= 1;
			reversed += (n % 2);

			n >>= 1;
		}

		return reversed;
	}
};

int main()
{
	Solution so;
	cout << so.reverseBits(1) << endl;
	cout << so.reverseBits(11) << endl;
	cout << so.reverseBits(232292) << endl;
	cout << so.reverseBits(43261596) << endl;

	return 0;
}
