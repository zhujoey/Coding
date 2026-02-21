//using erase and placing the 0s at the back, actually works
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        int amount = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                ++amount;
                --i;
            }
        }

        for (int i = 0; i < amount; ++i)
        {
            nums.push_back(0);
        }
    }
};