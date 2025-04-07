#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int>& nums)
    {
        std::vector<int> norepeat = {};
        int numofnum = 0;
        int i = 0;
        bool shouldcontinue = false;

        while (i <= nums.size() / 2)
        {
            numofnum = 0;
            shouldcontinue = false;

            for (int j = 0; j < norepeat.size(); ++j)
            {
                if (nums[i] == norepeat[j])
                {
                    ++i;
                    shouldcontinue = true;
                    break;
                }
            }

            if (shouldcontinue == true)
            {
                continue;
            }
            else
            {
                for (int k = i; k < nums.size(); ++k)
                {
                    if (nums[i] == nums[k])
                    {
                        ++numofnum;
                    }
                }
            }

            if (numofnum > nums.size() / 2)
            {
                return nums[i];
            }

            ++i;
        }

        return 0;
    }
};