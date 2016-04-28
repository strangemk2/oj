#include "leetcode.h"

class Solution
{
public:
	bool canWinNim(int n)
	{
		return (n % 4) != 0;
	}
};

int main()
{
	Solution so;
	cout << so.canWinNim(8) << endl;
}
