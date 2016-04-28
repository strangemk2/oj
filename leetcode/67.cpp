#include "leetcode.h"

class binary_string_number
{
private:
	string str;
	int pos = 0;

public:
	char top()
	{
		if (pos >= 0)
		{
			return str[pos];
		}
		else
		{
			return '0';
		}
	}

	bool unshift()
	{
		if (pos >= 0)
		{
			pos--;
			return true;
		}
		else
		{
			return false;
		}
	}

	binary_string_number(string s):str(s)
	{
		pos = s.length() - 1;
	}
};

class Solution
{
public:
    string addBinary(string a, string b)
	{
		binary_string_number bsn_a(a);
		binary_string_number bsn_b(b);

		string ret(max(a.length(), b.length()) + 1, '0');

		int carrige = 0;
		for (int i = ret.length() - 1; i >= 0; --i)
		{
			int n = 0;
			int sum = (bsn_a.top() - '0' + bsn_b.top() - '0' + carrige);
			carrige = sum / 2;
			n = sum % 2;
			ret[i] = n + '0';
			bsn_a.unshift();
			bsn_b.unshift();
		}
		if (ret[0] == '0')
		{
			ret.erase(0, 1);
		}
		return ret;
    }
};

int main()
{
	string a = "1111";
	string b = "101";

	Solution so;
	auto c = so.addBinary(a, b);
	cout << c << endl;

	return 0;
}
