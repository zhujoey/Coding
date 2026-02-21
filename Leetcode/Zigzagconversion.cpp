#include <string>
#include <vector>

class Solution
{
public:
    string convert(std::string s, int numrows)
    {
        if (numrows == 1)
        {
            return s;
        }

        std::vector<std::vector<char>> zigzag = {};
        std::vector<char> column = {};
        std::string answer = "";
        int startindex = 0;
        int index = 0;
        int temp = 0;

        while (index < s.size())
        {
            column = {};

            if (startindex == 0)
            {
                for (int i = index; i - index < numrows && i < s.size(); ++i)
                {
                    column.push_back(s[i]);
                    temp = i - index;
                }
                for (int j = 0; j < numrows - temp - 1; ++j)
                {
                    column.push_back('0');
                }

                zigzag.push_back(column);

                if (temp == s.size() - 1)
                {
                    
                    break;
                }
                else
                {
                    index = temp + index;
                    startindex = numrows - 2;
                }
            }
            else
            {
                for (int i = 0; i < startindex; ++i)
                {
                    column.push_back('0');
                }

                column.push_back(s[index]);

                for (int i = 0; i < numrows - startindex - 1; ++i)
                {
                    column.push_back('0');
                }

                --startindex;
                zigzag.push_back(column);
            }

            ++index;
        }

        for (int countindex = 0; countindex < numrows; ++countindex)
        {
            for (int countedvector = 0; countedvector < zigzag.size(); ++countedvector)
            {
                if (zigzag[countedvector][countindex] != '0')
                {
                    answer.push_back(zigzag[countedvector][countindex]);
                }
            }
        }

        return answer;
    }
};