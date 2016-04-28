#include "leetcode.h"

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		auto it = nums.begin();
		int result = *it;
		++it;

		for (; it < nums.end(); ++it)
		{
			result ^= *it;
		}

		return result;
	}
};

int main()
{
	vector<int> nums = {1,2,3,4,5,1,2,4,5};
	Solution so;
	cout << so.singleNumber(nums) << endl;

	return 0;
}
