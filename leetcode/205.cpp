#include "leetcode.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		map<char, char> morph_map;
		set<char> used_char;

		if (s.length() != t.length())
		{
			return false;
		}

		for (long i = 0; i < s.length(); i++)
		{
			auto it = morph_map.find(s[i]);
			if (it == morph_map.end())
			{
				if (used_char.find(t[i]) != used_char.end())
				{
					return false;
				}
				else
				{
					morph_map[s[i]] = t[i];
					used_char.insert(t[i]);
				}
			}
			else
			{
				if (it->second != t[i])
				{
					return false;
				}
			}
		}
		return true;
    }
};

int main()
{
	Solution so;
	cout << so.isIsomorphic("egg", "add") << endl;
	cout << so.isIsomorphic("foo", "bar") << endl;
	cout << so.isIsomorphic("paper", "title") << endl;
	cout << so.isIsomorphic("pepper", "jijjij") << endl;
}
