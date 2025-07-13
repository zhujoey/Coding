#include <string>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        std::string num = std::to_string(x);
        for (int i = 0; i < num.size() / 2; ++i)
        {
            if (num[i] != num[num.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};