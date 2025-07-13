#include <vector>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 1; j <= k && j <= i; ++j)
            {
                if (nums[i] == nums[i - j])
                {
                    return true;
                }
            }
        }

        return false;
    }
};