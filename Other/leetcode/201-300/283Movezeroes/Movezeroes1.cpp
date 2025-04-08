//written without erase, and exceeds time limit
//should work in theory
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        int temp = 0;

        nums.push_back(0); //so it doesn't overflow

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                temp = i;

                while (temp < nums.size() - 1 && nums[temp + 1] != 0)
                {
                    std::swap(nums[temp], nums[temp + 1]);
                    ++temp;
                    i = -1;
                }
            }
        }

        nums.pop_back();
    }
};