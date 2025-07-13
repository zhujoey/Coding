#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        int i = 0;
        int j = nums.size() - 1;

        while (nums[i] + nums[j] != target)
        {

            if (nums[i] + nums[j] < target)
            {
                i = i + 1;
            }

            else
            {
                j = j - 1;
            }
        }
        return {i + 1, j + 1};
    }
};