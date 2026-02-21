#include <vector>
#include <algorithm>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};