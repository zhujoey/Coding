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
        else if (s.size() == 1)
        {
            if (s[0] >= 48 && s[0] <= 57)
            {
                return s[0] - 48;
            }
            else
            {
                return 0;
            }
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
                if (ans > (pow(2, 31) + 47 - s[i]) / 10)
                {
                    if (multiplier == 1)
                    {
                        return pow(2, 31) - 1;
                    }
                    else
                    {
                        return 0 - pow(2, 31);
                    }
                }

                ans *= 10;
                ans += s[i] - 48;
                cout << ans << endl;
            }
            else
            {
                break;
            }
        }

        return ans * multiplier;
    }
};