#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        ++digits.back();
        int i = digits.size() - 1;
        while (digits[i] == 10)
        {
            if (i >= 1)
            {
                digits[i] = 0;
                ++digits[i - 1];
                --i;
            }
            else
            {
                digits[0] = 1;
                digits.push_back(0);
            }
        }
        return digits;
    }
};