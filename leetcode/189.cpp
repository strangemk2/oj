#include "leetcode.h"
#include <algorithm>

class Solution
{
public:
	void rotate_0(vector<int>& nums, int k)
	{
		k %= nums.size();
		if (k == 0) return;
		int back = nums.back();
		for (size_t i = nums.size() - 1; i >= 1; --i)
		{
			nums[i] = nums[i-1];
		}
		nums[0] = back;

		rotate(nums, k - 1);
	}

	void rotate(vector<int>& nums, int k)
	{
		k %= nums.size();
		int pos = nums.size() - k;
		reverse(nums.begin(), nums.begin() + pos);
		reverse(nums.begin() + pos, nums.end());
		reverse(nums.begin(), nums.end());
	}
};

int main()
{
	vector<int> nums{1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6};
	Solution so;
	so.rotate(nums, 9);
	for (auto n : nums) cout << n; cout << endl;
}

// 1234567
// 3217654
// 4567123
