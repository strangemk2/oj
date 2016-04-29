#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;

		if (numRows == 0)
		{
			return ret;
		}

		vector<int> v{1};
		ret.push_back(v);

		for (int i = 1; i < numRows; i++)
		{
			auto &prev = ret.back();

			vector<int> v(i+1);
			for (int j = 0; j < i+1; j++)
			{
				v[j] = get_value(prev, j - 1) + get_value(prev, j);
			}
			ret.push_back(v);
		}

		return ret;
    }
private:
	int get_value(const vector<int> &v, long pos)
	{
		if ((pos < 0) || (pos >= v.size())) return 0;
		return v[pos];
	}
};

int main()
{
    Solution so;
    auto a = so.generate(1);
    for (auto c : a) print_iteratable(c);

	cout << "-----------" << endl;

    auto b = so.generate(10);
    for (auto c : b) print_iteratable(c);
}
