#include <iostream>
#include <string>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        for (int i = 0; i < haystack.size(); ++i)
        {
            if (haystack[i] == needle[0])
            {
                if (needle.size() == 1)
                {
                    return i;
                }
                for (int j = 1; j < needle.size(); ++j)
                {
                    if (haystack[i + j] == needle[j])
                    {
                        if (j == needle.size() - 1)
                        {
                            return i;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return -1;
    }
};