//too slow

#include <string>

class Solution
{
public:
    std::string longestPalindrome(const std::string s)
    {
        std::string longest = "";
        std::string current = "";
        std::string temp = "";

        for (int i = 0; i < s.size(); ++i)
        {
            temp = "";
            temp.push_back(s[i]);
            current = recursive(s, temp, i, i);

            if (current.size() > longest.size())
            {
                longest = current;
            }
        }
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                temp = "";
                temp.push_back(s[i]);
                temp.push_back(s[i + 1]);
                current = recursive(s, temp, i, i + 1);

                if (current.size() > longest.size())
                {
                    longest = current;
                }
            }
            else
            {
                continue;
            }
        }

        return longest;
    }
    std::string recursive(const std::string string, std::string &current, const int start, const int end)
    {
        if (start > 0 && end < string.size() - 1 && string[start - 1] == string[end + 1])
        {
            current = string[start - 1] + current + string[end + 1];
            return recursive(string, current, start - 1, end + 1);
        }
        else
        {
            return current;
        }
    }
};