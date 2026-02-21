#include <vector>

class Solution
{
public:

    // Complexity: O(logN)
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        bool found = false;

        if(nums.empty())
        {
            return {-1, -1};
        }
        else if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                return {0, 0};
            }
            else
            {
                return {-1, -1};
            }
        }
        else if (nums.size() == 2)
        {
            if (nums[0] == target)
            {
                if (nums[1] == target)
                {
                    return {0, 1};
                }
                else
                {
                    return {0, 0};
                }
            }
            else
            {
                if (nums[1] == target)
                {
                    return {1, 1};
                }
                else
                {
                    return {-1, -1};
                }
            }
        }
        
        while (right - left > 1)
        {
            if (nums[(left + right) / 2] == target)
            {
                int temp = (left + right) / 2;
                right = temp;
                left = temp;
                found = true;
                break;
            }
            else if (nums[left] == target)
            {
                right = left;
                found = true;
                break;
            }
            else if (nums[right] == target)
            {
                left = right;
                found = true;
                break;
            }
            else if (nums[(left + right) / 2] < target)
            {
                left = (left + right) / 2;
            }
            else
            {
                right = (left + right) / 2;
            }
        }

        if (!found)
        {
            return {-1, -1};
        }

        while (left >= 0 && nums[left] == target)
        {
            --left;
        }
        ++left;
        while (right <= nums.size() - 1 && nums[right] == target)
        {
            ++right;
        }
        --right;
        
        return {left, right};
    }
};