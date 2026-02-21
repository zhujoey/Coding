#include <algorithm>
#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums[0] != nums[1])
        {
            return nums[0];
        }
        else if (nums[nums.size() - 1] != nums[nums.size() - 2])
        {
            return nums[nums.size() - 1];
        }

        for (int i = 1; i < nums.size() - 1; ++i)
        {
            if (nums[i - 1] != nums[i] && nums[i + 1] != nums[i])
            {
                return nums[i];
            }
        }

        return 0;
    }
};