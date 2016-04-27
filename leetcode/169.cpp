#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
	{
		int x;
		int count = 0;
		for (auto n : nums)
		{
			if (count == 0)
			{
				x = n;
				count++;
			}
			else if (x == n)
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		return x;
    }
};

int main()
{
	vector<int> v{1,1,2,2,2,2,2,1,2,3,2,2,4,5,1,1,2,2,2,2,1,1,4,6,3,1,1,5,2,1,1,1,1,1,2};
	Solution so;
	cout << so.majorityElement(v) << endl;
}
