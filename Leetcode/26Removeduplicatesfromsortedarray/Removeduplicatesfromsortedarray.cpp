#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        std::vector<int> norepeat = {nums[0]};
        for (int i = 1; i < nums.size(); ++i)
        {
            if (norepeat.size() > 0 && nums[i] != norepeat.back())
            {
                norepeat.push_back(nums[i]);
            }
        }
        norepeat.swap(nums);
        return nums.size();
    }
};