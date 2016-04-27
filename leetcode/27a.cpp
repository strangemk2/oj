#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        auto it = stable_partition(nums.begin(), nums.end(), [val](int n){return n != val;});
        return it - nums.begin();
    }
};

int main()
{
	vector<int> v{1,2,1,2};
	Solution so;
	so.removeElement(v, 2);
}
