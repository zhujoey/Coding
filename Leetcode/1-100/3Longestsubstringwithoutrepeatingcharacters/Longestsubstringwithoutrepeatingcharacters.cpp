#include <set>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty())
        {
            return 0;
        }
        
        int maxlen = 1;
        int lower = 0;

        for (int upper = 1; upper < s.size(); ++upper)
        {
            std::set<char> norepeat(s.begin() + lower, s.begin() + upper + 1);
            std::vector<char> repeat(s.begin() + lower, s.begin() + upper + 1);

            if (norepeat.size() == repeat.size())
            {
                if (norepeat.size() > maxlen)
                {
                    maxlen = norepeat.size();
                }
            }
            else
            {
                ++lower;
                --upper;
            }
        }

        return maxlen;
    }
};