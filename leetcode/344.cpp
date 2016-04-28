#include "leetcode.h"
#include <algorithm>

class Solution {
public:
    string reverseString(string s) {
		if (s.length() == 0) return s;

		size_t f = 0;
		size_t b = s.length() - 1;

		while (f < b)
		{
			swap(s[f], s[b]);
			f++;
			b--;
		}

		return s;
    }
};

int main()
{
	Solution so;
	cout << so.reverseString("") << endl;
}
