#include "leetcode.h"

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		int sum = 0;
		for (size_t i = 1; i <= nums.size(); ++i)
		{
			sum += i;
		}

		for (auto n : nums)
		{
			sum -= n;
		}
		return sum;
	}
};

int main()
{
	vector<int> nums{0, 1, 3, 2, 9, 10, 4, 5, 6, 8};
	//vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
	//vector<int> nums{45,35,38,13,12,23,48,15,44,21,43,26,6,37,1,19,22,3,11,32,4,16,28,49,29,36,33,8,9,39,46,17,41,7,2,5,27,20,40,34,30,25,47,0,31,42,24,10,14};
	Solution so;
	cout << so.missingNumber(nums) << endl;
	for (auto n : nums) cout << n << ','; cout << endl;

	return 0;
}
