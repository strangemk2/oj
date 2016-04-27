#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.size() == 0)
		{
			return "";
		}

		auto min_str_it = min_element(strs.begin(), strs.end(),
				[](const string &a, const string &b) {return a.length() < b.length();});
		int i = 0;
		for (;i < min_str_it->length(); ++i)
		{
			auto first_str = strs[0];
			for (auto &s : strs)
			{
				if (s[i] != first_str[i])
				{
					goto end;
				}
			}
		}
end:
		return strs[0].substr(0, i);
    }
};

int main()
{
	//vector<string> strs = {"abcdef", "abcaaa", "abcbbb", "abcddd"};
	vector<string> strs = {"", "abcd"};
	Solution so;
	cout << so.longestCommonPrefix(strs) << endl;
}
