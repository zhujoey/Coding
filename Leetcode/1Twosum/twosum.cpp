#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findnum(const std::vector<int>& numlist, int& target)
{
    std::vector<int> nums = numlist;
    std::sort(numlist.begin(), numlist.end());
    int i = 0;
    int j = numlist.size() - 1;

    while (numlist[i] + numlist[j] != target)
    {
        if (numlist[i] + numlist[j] < target)
        {
            ++i;
        }
        else
        {
            --j;
        }
    }
    int x = -1;
    int y = -1;
    for (int k = 0; k < nums.size(); ++k)
    {
        if (numlist[i] == nums[k] && x == -1)
        {
            x = k;
        }
        else if (numlist[j] == nums[k] && y == -1)
        {
            y = k;
        }
    }
    return std::vector<int>{x, y};
}

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        return findnum(nums, target);
    }
};