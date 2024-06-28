#include <iostream>
#include <string>

class Solution {
public:
    int romanToInt(const std::string& s)
    {
        int value = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'I')
            {
                if (i < s.size() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                {
                    --value;
                }
                else
                {
                    ++value;
                }
            }
            else if (s[i] == 'V')
            {
                value += 5;
            }
            else if (s[i] == 'X')
            {
                if (i < s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                {
                    value -= 10;
                }
                else
                {
                    value += 10;
                }
            }
            else if (s[i] == 'L')
            {
                value += 50;
            }
            else if (s[i] == 'C')
            {
                if (i < s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                {
                    value -= 100;
                }
                else
                {
                    value += 100;
                }
            }
            else if (s[i] == 'D')
            {
                value += 500;
            }
            else if (s[i] == 'M')
            {
                value += 1000;
            }
        }
        return value;
    }
};