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
            if (remainders[i] == 1)
            {
                columnname.push_back('A');
            }
            else if (remainders[i] == 2)
            {
                columnname.push_back('B');
            }
            else if (remainders[i] == 3)
            {
                columnname.push_back('C');
            }
            else if (remainders[i] == 4)
            {
                columnname.push_back('D');
            }
            else if (remainders[i] == 5)
            {
                columnname.push_back('E');
            }
            else if (remainders[i] == 6)
            {
                columnname.push_back('F');
            }
            else if (remainders[i] == 7)
            {
                columnname.push_back('G');
            }
            else if (remainders[i] == 8)
            {
                columnname.push_back('H');
            }
            else if (remainders[i] == 9)
            {
                columnname.push_back('I');
            }
            else if (remainders[i] == 10)
            {
                columnname.push_back('J');
            }
            else if (remainders[i] == 11)
            {
                columnname.push_back('K');
            }
            else if (remainders[i] == 12)
            {
                columnname.push_back('L');
            }
            else if (remainders[i] == 13)
            {
                columnname.push_back('M');
            }
            else if (remainders[i] == 14)
            {
                columnname.push_back('N');
            }
            else if (remainders[i] == 15)
            {
                columnname.push_back('O');
            }
            else if (remainders[i] == 16)
            {
                columnname.push_back('P');
            }
            else if (remainders[i] == 17)
            {
                columnname.push_back('Q');
            }
            else if (remainders[i] == 18)
            {
                columnname.push_back('R');
            }
            else if (remainders[i] == 19)
            {
                columnname.push_back('S');
            }
            else if (remainders[i] == 20)
            {
                columnname.push_back('T');
            }
            else if (remainders[i] == 21)
            {
                columnname.push_back('U');
            }
            else if (remainders[i] == 22)
            {
                columnname.push_back('V');
            }
            else if (remainders[i] == 23)
            {
                columnname.push_back('W');
            }
            else if (remainders[i] == 24)
            {
                columnname.push_back('X');
            }
            else if (remainders[i] == 25)
            {
                columnname.push_back('Y');
            }
            else if (remainders[i] == 26 || remainders[i] == 0)
            {
                columnname.push_back('Z');
            }
        }

        return std::string(columnname.begin(), columnname.end());
    }
};