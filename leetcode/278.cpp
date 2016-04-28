#include "leetcode.h"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
	{
		return bsearch(1, n);
    }

	int bsearch(int low, int high)
	{
		if (high == low)
		{
			if (isBadVersion(low)) return low;
			else return 0;
		}

		if (high - low == 1)
		{
			if (!isBadVersion(low)) return high;
			else return 1;
		}

		unsigned int mid = (low + high);
		mid /= 2;
		if (isBadVersion(mid))
		{
			return bsearch(low, mid);
		}
		else
		{
			return bsearch(mid, high);
		}
	}
};

bool isBadVersion(int version)
{
	if (version >= 1702766719) return true;
	return false;
}

int main()
{
	Solution so;
	cout << so.firstBadVersion(2126753390) << endl;
}
