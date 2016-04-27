#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
	{
		stack<char> parent_stack;
		for (auto ch : s)
		{
			switch (ch)
			{
				case '(':
				case '{':
				case '[':
					parent_stack.push(ch);
					break;
				default:
					if (parent_stack.size() == 0)
					{
						return false;
					}
					char last_char = parent_stack.top();
					if ((last_char == '(' && ch == ')') ||
						(last_char == '[' && ch == ']') ||
						(last_char == '{' && ch == '}'))
					{
						parent_stack.pop();
					}
					else
					{
						return false;
					}
					break;
			}
		}
		if (parent_stack.size() != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
    }
};

int main()
{
	Solution so;
	cout << so.isValid("{[[]()]({})}") << endl;
}
