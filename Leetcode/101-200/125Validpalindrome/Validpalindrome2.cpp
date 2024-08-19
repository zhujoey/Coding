#include <string>
#include <vector>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        std::vector<char> raw = {};
        for (int i = 0; i < s.size(); ++i)
        {
            if ((s[i] < 58 && s[i] > 47) || (s[i] > 96 && s[i] < 123))
            {
                raw.push_back(s[i]);
            }
            else if (s[i] > 64 && s[i] < 91)
            {
                raw.push_back(s[i] + 32);
            }
        }
        if (raw == std::vector<char> (raw.rbegin(), raw.rend()))
        {
            return true;
        }
        return false;
    }
};