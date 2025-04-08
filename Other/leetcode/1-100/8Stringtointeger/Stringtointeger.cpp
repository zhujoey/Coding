//48 and 57 is the ASCII range for int

#include <string>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        if (s.empty())
        {
            return 0;
        }

        int ans = 0;
        int multiplier = 1;
        int start = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                break;
            }
            
            start = i + 1;
        }

        if (s[start] == '-')
        {
            multiplier = -1;
            ++start;
        }
        else if (s[start] == '+')
        {
            ++start;
        }

        for (int i = start; i < s.size(); ++i)
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                if (ans > (2147483647 - s[i] + 48) / 10)
                {
                    //+ 48 because negatives have a bigger range
                    if (multiplier == 1)
                    {
                        return 2147483647;
                        //max limit
                    }
                    else
                    {
                        return -2147483648;
                        //max limit
                    }
                }

                ans *= 10;
                ans += s[i] - 48;
            }
            else
            {
                break;
            }
        }

        return ans * multiplier;
    }
};