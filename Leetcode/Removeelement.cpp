#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        std::vector<int> stay = {};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                stay.push_back(nums[i]);
            }
        }

        nums.swap(stay);
        return nums.size();
    }
};