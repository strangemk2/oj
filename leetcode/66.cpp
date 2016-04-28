#include "leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		for (long i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] < 9)
			{
				digits[i]++;
				break;
			}
			else
			{
				digits[i] = 0;
			}
		}
		if (digits[0] == 0)
		{
			digits.insert(digits.begin(), 1);
		}

		return digits;
    }
};

int main()
{
	Solution so;
	vector<int> a{9};
	print_iteratable(so.plusOne(a));
	vector<int> b{9,2,9};
	print_iteratable(so.plusOne(b));
	vector<int> c{1,9,9};
	print_iteratable(so.plusOne(c));
	vector<int> d{9,9,9};
	print_iteratable(so.plusOne(d));

	return 0;
}
