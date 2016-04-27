class Solution {
public:
    void swap(int &a, int &b)
    {
        auto t = a;
        a = b;
        b = t;
    }
    int removeElement(vector<int>& nums, int val)
    {
        int last = nums.size() - 1;
        for (int i = 0; i <= last; ++i)
        {
            if (nums[i] == val)
            {
                while (nums[last] == val && last > i)
                {
                    last--;
                }
                swap(nums[i], nums[last]);
                last--;
            }
        }
        return last + 1;
    }
};
