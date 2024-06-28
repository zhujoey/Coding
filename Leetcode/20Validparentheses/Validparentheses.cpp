#include <iostream>
#include <vector>

class Solution
{
public:
    bool isValid(string s)
    {
        std::vector<char> string = {};
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                string.push_back(s[i]);
            }
            else if (s[i] == ')')
            {
                if (string.empty())
                {
                    return false;
                }
                else if (string.back() == '(')
                {
                    string.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (string.empty())
                {
                    return false;
                }
                else if (string.back() == '[')
                {
                    string.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if (string.empty())
                {
                    return false;
                }
                else if (string.back() == '{')
                {
                    string.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        return string.empty();
    }
};