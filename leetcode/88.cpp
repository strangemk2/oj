#include "leetcode.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        long index1 = m - 1;
		long index2 = n - 1;
		long index_m = m + n - 1;

		while (index_m >= 0)
		{
			if ((index1 >= 0 && index2 < 0) || (index1 >= 0 && index2 >= 0 && nums1[index1] > nums2[index2]))
			{
				nums1[index_m] = nums1[index1];
				index1--;
			}
			else
			{
				nums1[index_m] = nums2[index2];
				index2--;
			}
			index_m--;
		}
    }
};

int main()
{
	vector<int> nums1{1,3,5,6,9,0,0,0,0,0};
	vector<int> nums2{2};

	Solution so;
	so.merge(nums1, 0, nums2, 5);

	print_iteratable(nums1);

	return 0;
}
