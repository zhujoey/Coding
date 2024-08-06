#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s)
    {
        int chars = 0;
        bool isspace = true;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
            {
                isspace = false;
                ++chars;
            }
            else if (s[i] == ' ' && isspace == false)
            {
                return chars;
            }
        }
        return chars;
    }
};