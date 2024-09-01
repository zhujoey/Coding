#include <vector>
#include <algorithm>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        if (nums.size() == 2 && nums[0] == nums[1])
        {
            return true;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i + 1])
            {
                return true;
            }
        }

        return false;
    }
};