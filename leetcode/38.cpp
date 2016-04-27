#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string read_continue_sequence(string &s)
	{
		if (s.length() == 0) return "";

		int count = 0;
		char ch = s[0];
		while (count < s.length())
		{
			if (s[count] != ch)
			{
				break;
			}
			count++;
		}
		auto ret = string(2, ch);
		ret[0] = count + '0';
		s = s.substr(count);
		return ret;
	}

	string convert_string(string &s)
	{
		string ret;
		while (s.length() > 0)
		{
			ret += read_continue_sequence(s);
		}
		return ret;
	}

    string countAndSay(int n)
	{
		if (n == 0) return "";

		string ret = "1";
		if (n == 1) return ret;

		for (int i = 1; i < n; ++i)
		{
			ret = convert_string(ret);
			cout << ret << endl;
		}
		return ret;
    }
};

int main()
{
	Solution so;
	cout << so.countAndSay(20) << endl;
}
