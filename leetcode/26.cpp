class Solution {
public:
    int skip_duplicate(const vector<int>& nums, int i)
    {
        auto current = nums[i];
        while (nums[i] == current && i < nums.size())
        {
            i++;
        }
        return i;
    }
    
    int removeDuplicates(vector<int>& nums)
    {
        auto size = nums.size();
        if (size <= 1)
        {
            return size;
        }
        
        int new_index = 0;
        int original_index = 0;
        while (true)
        {
            auto next_index = skip_duplicate(nums, original_index);
            size -= (next_index - original_index - 1);
            original_index = next_index;
            if (original_index != nums.size())
            {
                nums[++new_index] = nums[original_index];
            }
            else
            {
                break;
            }
        }
        
        return size;
    }
};
