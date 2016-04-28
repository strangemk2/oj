#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;

		// store the minimum until ith element
		vector<int> min(prices.size(), prices[0]);
		for (size_t i = 1; i < prices.size(); i++)
		{
			if (prices[i] < min[i-1])
			{
				min[i] = prices[i];
			}
			else
			{
				min[i] = min[i-1];
			}
		}

		int max = 0;
		for (size_t i = 0; i < prices.size(); i++)
		{
			auto profit = prices[i] - min[i];
			if (max < profit)
			{
				max = profit;
			}
		}

		return max;
    }
};

int main()
{
	Solution so;
	vector<int> a = {1,2,3,4,5};
	cout << so.maxProfit(a) << endl;
	vector<int> b = {2};
	cout << so.maxProfit(b) << endl;
	vector<int> c = {5,5,5,5,5};
	cout << so.maxProfit(c) << endl;
	vector<int> d = {5,5,6,5,4};
	cout << so.maxProfit(d) << endl;
	vector<int> e = {5,6,3,6,4};
	cout << so.maxProfit(e) << endl;
	vector<int> f;
	cout << so.maxProfit(f) << endl;
	vector<int> g = {4, 1, 2};
	cout << so.maxProfit(g) << endl;
}
