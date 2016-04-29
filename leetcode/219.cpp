#include "leetcode.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, long> elements;
		for (long i = 0; i < nums.size(); i++)
		{
			auto e = elements.find(nums[i]);
			if (e == elements.end() || ((i - e->second) > k))
			{
				elements[nums[i]] = i;
			}
			else
			{
				return true;
			}
		}
		return false;
    }
};

int main()
{
	vector<int> nums{1,2,3,4,5,6,7,8,9};
	Solution so;
	cout << so.containsNearbyDuplicate(nums, 0) << endl;
	return 0;
}
