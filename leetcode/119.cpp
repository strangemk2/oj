#include "leetcode.h"

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ret(rowIndex+1);
		vector<int> buf(rowIndex+1);

		buf[0] = 1;

		vector<int> *current = &ret;;
		vector<int> *prev = &buf;

		for (int i = 0; i < rowIndex+1; i++)
		{
			for (int j = 0; j < i+1; j++)
			{
				(*current)[j] = get_value(*prev, j - 1) + get_value(*prev, j);
			}
			swap(current, prev);
		}

		return *prev;
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
    auto a = so.getRow(1);
    print_iteratable(a);

	cout << "-----------" << endl;

    auto b = so.getRow(0);
    print_iteratable(b);
}
