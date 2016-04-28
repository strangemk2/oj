#include "leetcode.h"
#include <unordered_set>
#include <set>

using namespace std;

class Solution
{
public:
	bool wordBreak_recursive(string s, unordered_set<string>& wordDict)
	{
		if (s.length() == 0)
		{
			return true;
		}

		for (size_t i = 1; i <= s.length(); ++i)
		{
			auto lead = s.substr(0, i);
			if (wordDict.count(lead))
			{
				cout << lead << endl;
				cout << s.substr(i) << endl;
				if (wordBreak(s.substr(i), wordDict))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool wordBreak_dp(string s, vector<int> &breakable, unordered_set<string> &wordDict, set<int> &word_size)
	{
		for (size_t i = 0; i < s.length(); ++i)
		{
			//for (auto i : breakable) cout << i; cout << endl;
			if (wordDict.count(s.substr(0, i + 1)))
			{
				breakable[i] = 1;
				continue;
			}
			for (auto it = word_size.begin(); it != word_size.end(); ++it)
			{
				int index = i - *it;
				if (index < 0) continue;
				//cout << breakable[index] << "," << index << ',' << wordDict.count(s.substr(index+1, *it)) << endl;
				if (breakable[index] == 1 && wordDict.count(s.substr(index+1, *it)))
				{
					//cout << i << endl;
					breakable[i] = 1;
					break;
				}
			}
		}
		//for (auto i : breakable) cout << i; cout << endl;

		return breakable.back();
	}

	bool wordBreak(string s, unordered_set<string>& wordDict)
	{
		vector<int> breakable(s.length(), 0);
		set<int> word_size;
		for (auto it = wordDict.begin(); it != wordDict.end(); ++it)
		{
			word_size.insert(it->length());
		}
		return wordBreak_dp(s, breakable, wordDict, word_size);
	}
};

int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//string s = "aaaaaaaaaaaaaaab";
	unordered_set<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaab"};
	//string s = "leetcode";
	//unordered_set<string> dict{"le", "et", "code"};
	Solution so;
	cout << so.wordBreak(s, dict) << endl;
}
