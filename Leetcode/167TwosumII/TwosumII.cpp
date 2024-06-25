#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findnum(std::vector<int> numlist, int target)
{
    int i = 0;
    int j = numlist.size() - 1;

    while (numlist[i] + numlist[j] != target)
    {

        if (numlist[i] + numlist[j] < target)
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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return findnum(nums, target);
    }
};