#include "leetcode.h"
#include <functional>

class Solution
{
public:
	function<string ()> string_reader(string &str)
	{
		return [&str]() {
			if (str.length() == 0) return str;
			auto pos = str.find('.');
			if (pos == string::npos)
			{
				auto ret = str;
				str = "";
				return ret;
			}

			auto ret = str.substr(0, pos);
			str = str.substr(pos+1);
			return ret;
		};
	}

	int compareVersion(string version1, string version2)
	{
		auto v1reader = string_reader(version1);
		auto v2reader = string_reader(version2);
		string v1, v2;
		do
		{
			v1 = v1reader();
			v2 = v2reader();
			cout << v1 << "," << v2 << endl;
			auto n1 = v1.length() == 0?0:stoi(v1);
			auto n2 = v2.length() == 0?0:stoi(v2);

			if (n1 > n2) return 1;
			if (n1 < n2) return -1;
		}
		while (v1.length() != 0 || v2.length() != 0);
		return 0;
	}
};

int main()
{
	Solution so;
	cout << so.compareVersion("1.23.0.0", "1.23.0") << endl;

	return 0;
}
