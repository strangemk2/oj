#include "leetcode.h"
#include <set>
#include <limits>
#include <cmath>

class Solution
{
public:
	bool isPowerOfThree(int n)
	{
		set<int> power_of_tree_set{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
		return power_of_tree_set.count(n);
	}
};

int main()
{
	long long power = 0;
	int n = 0;
	while (power < std::numeric_limits<int>::max())
	{
		cout << power << endl;
		power = pow(3, ++n);
	}
	cout << n;

	return 0;
}
