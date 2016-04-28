#include "leetcode.h"
#include "algorithm"

class Solution
{
public:
    void sortColors(vector<int>& nums)
	{
		auto it = partition(nums.begin(), nums.end(), [](int i){return (i == 0);});
		partition(it, nums.end(), [](int i){return (i == 1);});
    }
};

int main()
{
	vector<int> nums{};
	Solution so;
	so.sortColors(nums);
	print_iteratable(nums);

	return 0;
}
