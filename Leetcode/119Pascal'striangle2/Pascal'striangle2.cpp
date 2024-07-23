#include <vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
        {
            return {1};
        }
        else if (rowIndex == 1)
        {
            return {1,1};
        }

        std::vector<int> numbers = {};
        std::vector<int> previous = {1, 1};
        for (int i = 1; i < rowIndex; ++i)
        {
            numbers.clear();
            numbers.push_back(1);
            for (int j = 0; j < previous.size() - 1; ++j)
            {
                numbers.push_back(previous[j] + previous[j + 1]);
            }

            numbers.push_back(1);
            previous.swap(numbers);
        }
        return previous;
    }
};