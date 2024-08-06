#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int> removed = {};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                removed.push_back(nums[i]);
            }
        }
        nums.swap(removed);
        return nums.size();
    }
};