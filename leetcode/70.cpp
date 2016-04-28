#include "leetcode.h"

class Solution {
public:
    int climbStairs(int n)
	{
		static vector<int> result{0};
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;

		if (result.size() < n)
		{
			result.resize(n, 0);
		}

		if (result[n-1] != 0)
		{
			return result[n-1];
		}
		else
		{
			result[n-1] = climbStairs(n - 2) + climbStairs(n - 1);
		}

		return result[n-1];
	}
};

int main()
{
	Solution so;
	cout << so.climbStairs(1) << endl;
	cout << so.climbStairs(2) << endl;
	cout << so.climbStairs(3) << endl;
	cout << so.climbStairs(4) << endl;
	cout << so.climbStairs(10) << endl;
	cout << so.climbStairs(30) << endl;
}
