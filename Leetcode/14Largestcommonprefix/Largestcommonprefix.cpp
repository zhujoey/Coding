#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        std::vector<char> commonprefix = {};
        int shortest = strs[0].size();
        for (int i = 1; i < strs.size(); ++i)
        {
            if (strs[i].size() < shortest)
            {
                shortest = strs[i].size();
            }
        }
        for (int j = 0; j < shortest; ++j)
        {
            char compare = strs[0][j];
            for (int k = 1; k < strs.size(); ++k)
            {
                if (strs[k][j] != compare)
                {
                    return std::string (commonprefix.begin(), commonprefix.end());
                }
            }
            commonprefix.push_back(compare);
        }
        return std::string (commonprefix.begin(), commonprefix.end());
    }
};