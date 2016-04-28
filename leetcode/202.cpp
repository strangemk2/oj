#include "leetcode.h"
#include <set>

class Solution
{
public:
	bool isHappy_impl(int n, set<int> &generated_num)
	{
		int sum = 0;
		while (n > 0)
		{
			auto mod = (n % 10);
			sum += (mod * mod);
			n /= 10;
		}
		if (sum == 1)
		{
			return true;
		}
		if (generated_num.count(sum))
		{
			return false;
		}
		else
		{
			generated_num.insert(sum);
			return isHappy_impl(sum, generated_num);
		}
	}

	bool isHappy(int n)
	{
		set<int> generated_num;
		return isHappy_impl(n, generated_num);
	}
};

int main()
{
	Solution so;
	cout << so.isHappy(13) << endl;

	return 0;
}
