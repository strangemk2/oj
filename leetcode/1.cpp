#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int> remains;
		vector<int> ret;
		for (int i = 0; i < nums.size(); ++i)
		{
			remains[target - nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			if (remains.count(nums[i]))
			{
				if (remains[nums[i]] != i)
				{
					ret.push_back(i);
					ret.push_back(remains[nums[i]]);
					return ret;
				}
			}
		}
		return ret;
    }
};

int main()
{
	vector<int> nums{3,3,4};
	int target = 6;

	Solution so;
	for (auto n : so.twoSum(nums, target))
	{
		cout << n << " ";
	}
	cout << endl;

	return 0;
}
