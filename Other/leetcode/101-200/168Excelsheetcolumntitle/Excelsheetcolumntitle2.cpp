#include <string>
#include <vector>

// second way: use ascii instead of a lot of if statements

class Solution
{
public:
    std::string convertToTitle(int columnnumber)
    {
        std::vector<int> remainders = {};
        std::vector<char> columnname = {};
        while (columnnumber > 26)
        {
            if (columnnumber % 26 == 0)
            {
                // when the number can divide 26, the quotient will be 1 larger than it is supposed to be, this deals with the letter Z
                remainders.push_back(26);
                columnnumber /= 26;
                columnnumber -= 1;
            }
            else
            {
                remainders.push_back(columnnumber % 26);
                columnnumber /= 26;
            }
        }
        remainders.push_back(columnnumber % 26);

        for (int i = remainders.size() - 1; i >= 0; --i)
        {
            if (remainders[i] == 0)
            {
                columnname.push_back('Z');
            }
            else
            {
                columnname.push_back(static_cast<char>(remainders[i] + 64));
            }
        }

        return std::string(columnname.begin(), columnname.end());
    }
};