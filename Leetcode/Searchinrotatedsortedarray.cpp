#include <vector>

class Solution
{
public:
    // Complexity: O(2logN)
    int search(std::vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        if (nums[right / 2] >= nums[0] && nums[right / 2] <= nums[right])
        {
            while (right - left > 1)
            {
                if (nums[(left + right) / 2] == target)
                {
                    return (left + right) / 2;
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

            if (nums[left] == target)
            {
                return left;
            }
            else if (nums[right] == target)
            {
                return right;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            int pivot = 0;
            while (true)
            {
                if (nums[(right + left) / 2] > nums[(right + left) / 2 + 1])
                {
                    pivot = (right + left) / 2 + 1;
                    break;
                }
                else if (nums[(right + left) / 2] > nums[right])
                {
                    left = (right + left) / 2;
                }
                else
                {
                    right = (right + left) / 2;
                }
            }

            if (target >= nums[0])
            {
                left = 0;
                right = pivot;

                while (right - left > 1)
                {
                    if (nums[(left + right) / 2] == target)
                    {
                        return (left + right) / 2;
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
            }
            else
            {
                left = pivot - 1;
                right = nums.size() - 1;

                while (right - left > 1)
                {
                    if (nums[(left + right) / 2] == target)
                    {
                        return (left + right) / 2;
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
            }

            if (nums[left] == target)
            {
                return left;
            }
            else if (nums[right] == target)
            {
                return right;
            }
            else
            {
                return -1;
            }
        }
    }
};