#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int maxlimit = nums.size() - 1;
        int minlimit = 0;
        int average = maxlimit / 2;
        while (maxlimit - 1 > minlimit)
        {
            if (nums[average] == target)
            {
                return average;
            }
            else if (nums[average] < target)
            {
                minlimit = average;
            }
            else
            {
                maxlimit = average;
            }
            average = (minlimit + maxlimit) / 2;
        }
        if (target > nums.back())
        {
            return nums.size();
        }
        else if (target <= nums.front())
        {
            return 0;
        }
        else
        {
            return maxlimit;
        }
    }
};