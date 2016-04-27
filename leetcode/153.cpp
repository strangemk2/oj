#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
	{
		return find_min_impl(nums, 0, nums.size() - 1);
    }

	int find_min_impl(const vector<int> &nums, size_t low, size_t high)
	{
		if (low == high) return nums[low];
		if (high - low == 1) return nums[low] < nums[high] ? nums[low] : nums[high];

		auto mid = (low + high) / 2;
		if (nums[mid] > nums[high])
		{
			return find_min_impl(nums, mid, high);
		}
		else
		{
			return find_min_impl(nums, low, mid);
		}
	}
};

int main()
{
	vector<int> v{5, 6, 7, 8, 9, 10, 11, -2, 0, 1, 2, 3, 4};
	Solution so;
	cout << so.findMin(v) << endl;;

	return 0;
}
