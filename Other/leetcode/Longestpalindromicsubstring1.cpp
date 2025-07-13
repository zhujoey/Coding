//slow

#include <string>

class Solution
{
public:
    std::string longestPalindrome(const std::string s)
    {
        if (s.size() == 1)
        {
            return s;
        }

        int temp = 0;
        std::string result = "";
        std::string substring = "";

        result.push_back(s[0]);

        for (int i = 0; i < s.size(); ++i)
        {
            substring = "";
            substring.push_back(s[i]);
            temp = s.size() - i - 1;

            for (int j = 1; j <= std::min(i, temp); ++j)
            {
                if (s[i - j] == s[i + j])
                {
                    substring = s[i - j] + substring + s[i + j];
                }
                else
                {
                    break;
                }

                if (substring.size() > result.size())
                {
                    result = substring;
                }
            }
        }

        for (int i = 0; i < s.size() - 1; ++i)
        {
            substring = "";
            substring.push_back(s[i]);
            substring.push_back(s[i + 1]);

            temp = s.size() - i - 2;

            for (int j = 0; j <= std::min(i, temp); ++j)
            {
                if (s[i - j] == s[i + j + 1])
                {
                    if (j > 0)
                    {
                        substring = s[i - j] + substring + s[i + j + 1];
                    }
                }
                else
                {
                    break;
                }

                if (substring.size() > result.size())
                {
                    result = substring;
                }
            }
        }

        return result;
    }
};