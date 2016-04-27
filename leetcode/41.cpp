#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int firstMissingPositive(vector<int>& nums)
		{
			for (int i = 0; i < nums.size();)
			{
				if (nums[i] < i || nums[i] > nums.size())
				{
					++i;
				}
				else if (nums[i] != (i + 1))
				{
					int real_index = nums[i] - 1;
					swap(nums[real_index], nums[i]);
				}
				else
				{
					++i;
				}
			}

			for (auto n : nums)
			{
				cout << n;
			}
			cout << endl;

			return 2;
		}

		void swap(int &a, int &b)
		{
			int c = a;
			a = b;
			b = c;
		}
};

int main()
{
	vector<int> nums = {23, 45, 98};
	Solution s;
	cout << s.firstMissingPositive(nums) << endl;
}
