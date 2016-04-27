#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	void gen_parenthesis(int left_count, int right_count, string &str, vector<string> &result)
	{
		if (left_count == 0 && right_count == 0)
		{
			result.push_back(str);
			return ;
		}

		if (left_count < 0 || left_count > right_count)
		{
			return;
		}

		if (left_count > 0)
		{
			str.push_back('(');
			gen_parenthesis(left_count - 1, right_count, str, result);
			str.pop_back();
		}

		if (left_count < right_count)
		{
			str.push_back(')');
			gen_parenthesis(left_count, right_count - 1, str, result);
			str.pop_back();
		}
	}

    vector<string> generateParenthesis(int n)
	{
		vector<string> ret;
		string str;
		gen_parenthesis(n, n, str, ret);
		return ret;
    }
};

int main()
{
	Solution so;
	for (const auto &s : so.generateParenthesis(5))
	{
		cout << s << " ";
	}
	cout << endl;
}
