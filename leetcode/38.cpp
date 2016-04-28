#include "leetcode.h"

class Solution
{
public:
	string count(const string &s)
	{
		char current = 0;
		int count = 0;
		string ret;

		for (auto c : s)
		{
			if (current == c)
			{
				count++;
			}
			else
			{
				if (current != 0)
				{
					ret += (count + '0');
					ret += current;
				}

				current = c;
				count = 1;
			}
		}
		ret += count + '0';
		ret += current;

		return ret;
	}

    string countAndSay(int n)
	{
		if (n < answer.size())
		{
			return answer[n];
		}

		while (answer.size() <= n)
		{
			answer.push_back(count(answer.back()));
		}

		return answer.back();
	}

private:
	vector<string> answer = {"", "1"};
};

int main()
{
	Solution so;
	cout << so.countAndSay(1) << endl;
	cout << so.countAndSay(2) << endl;
	cout << so.countAndSay(3) << endl;
	cout << so.countAndSay(4) << endl;
	cout << so.countAndSay(5) << endl;
	cout << so.countAndSay(6) << endl;
	cout << so.countAndSay(7) << endl;
	cout << so.countAndSay(8) << endl;
	cout << so.countAndSay(9) << endl;
	cout << so.countAndSay(10) << endl;
	cout << so.countAndSay(11) << endl;
	cout << so.countAndSay(21) << endl;
	cout << so.countAndSay(22) << endl;

	return 0;
}
