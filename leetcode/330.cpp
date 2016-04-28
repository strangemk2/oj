#include "leetcode.h"

class Solution
{
public:
/*
	void pick_num(const vector<int> &nums, size_t n, size_t start, vector<vector<int>> &result)
	{
		static vector<int> num_set;
		for (size_t i = start; i < nums.size(); ++i)
		{
			num_set.push_back(nums[i]);
			if (num_set.size() == n)
			{
				result.push_back(num_set);
			}
			else
			{
				pick_num(nums, n, i + 1, result);
			}
			num_set.pop_back();
		}
	}

	int minPatches(vector<int>& nums, int n)
	{
		vector<vector<int>> result;
		for (size_t i = 1; i <= nums.size(); ++i)
		{
			vector<vector<int>> l_result;
			pick_num(nums, i, 0, l_result);
			result.insert(result.end(), l_result.begin(), l_result.end());
		}

		vector<int> pattern_sum{0};
		for (const auto &pattern : result)
		{
			int sum = 0;
			for (auto num : pattern)
			{
				sum += num;
			}
			pattern_sum.push_back(sum);
		}

		vector<vector<int>> missing_nums;
		for (int i = 1; i <= n; ++i)
		{
			vector<int> missing_num;
			bool save_flag = true;
			for (auto num : pattern_sum)
			{
				auto d = i - num;
				if (d == 0)
				{
					save_flag = false;
				}
				if (d > 0)
				{
					missing_num.push_back(d);
				}
			}
			if (missing_num.size() > 0 && save_flag)
			{
				missing_nums.push_back(missing_num);
			}
		}

		for (auto &missing_num : missing_nums)
		{
			for (auto num : missing_num)
			{
				cout << num << ",";
			}
			cout << endl;
		}

		return 0;
	}
*/
	int minPatches(vector<int>& nums, int n)
	{
		int current_max = 1;
		size_t i = 0;
		int ret = 0;

		while (current_max <= n)
		{
			if (i < nums.size() && nums[i] <= current_max)
			{
				current_max += nums[i];
				i++;
			}
			else
			{
				cout << current_max << ",";
				current_max += current_max;
				ret++;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> num{1,2,2,9};
	Solution so;
	cout << so.minPatches(num, 2000) << endl;
}
