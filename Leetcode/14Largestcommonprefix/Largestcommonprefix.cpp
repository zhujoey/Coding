#include <iostream>
#include <string>
#include <vector>

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
        // need to prevent overflow in the next loop by finding shortest length first
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
        // compares all of the chars in index j with the first
        return std::string (commonprefix.begin(), commonprefix.end());
    }
};