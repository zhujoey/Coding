#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }
        else if (numRows == 2)
        {
            return {{1}, {1,1}};
        }

        std::vector<int> numbers = {};
        std::vector<int> previous = {1, 1};
        std::vector<std::vector<int>> answer = {{1}};
        for (int i = 1; i < numRows; ++i)
        {
            numbers.clear();
            numbers.push_back(1);
            for (int j = 0; j < previous.size() - 1; ++j)
            {
                numbers.push_back(previous[j] + previous[j + 1]);
            }

            numbers.push_back(1);
            previous.swap(numbers);
            answer.push_back(numbers);
        }
        return answer;
    }
};