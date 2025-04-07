#include <string>
#include <vector>

class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits == "")
        {
            return {};
        }
        return makeLetterCombinationsRecursively(digits, digits.size() - 1);
    }

    // Complexity: O(n ^ 2)
    std::vector<std::string> makeLetterCombinationsRecursively(std::string digits, int index)
    {
        if (index == -1)
        {
            return {""};
        }

        std::vector<std::string> result = {};
        std::vector<std::string> temp = makeLetterCombinationsRecursively(digits, index - 1);
        int times = 0;

        if(digits[index] == '7' || digits[index] == '9')
        {
            times = 4;
        }
        else
        {
            times = 3;
        }

        for (int i = 0; i < times; ++i)
        {
            result.insert(result.end(), temp.begin(), temp.end());
        }
        
        if (digits[index] == '2')
        {
            for (int i = 0; i < result.size() / 3; ++i)
            {
                result[i].push_back('a');
            }
            for (int i = result.size() / 3; i < result.size() / 3 * 2; ++i)
            {
                result[i].push_back('b');
            }
            for (int i = result.size() / 3 * 2; i < result.size(); ++i)
            {
                result[i].push_back('c');
            }
        }
        else if (digits[index] == '3')
        {
            for (int i = 0; i < result.size() / 3; ++i)
            {
                result[i].push_back('d');
            }
            for (int i = result.size() / 3; i < result.size() / 3 * 2; ++i)
            {
                result[i].push_back('e');
            }
            for (int i = result.size() / 3 * 2; i < result.size(); ++i)
            {
                result[i].push_back('f');
            }
        }
        else if (digits[index] == '4')
        {
            for (int i = 0; i < result.size() / 3; ++i)
            {
                result[i].push_back('g');
            }
            for (int i = result.size() / 3; i < result.size() / 3 * 2; ++i)
            {
                result[i].push_back('h');
            }
            for (int i = result.size() / 3 * 2; i < result.size(); ++i)
            {
                result[i].push_back('i');
            }
        }
        else if (digits[index] == '5')
        {
            for (int i = 0; i < result.size() / 3; ++i)
            {
                result[i].push_back('j');
            }
            for (int i = result.size() / 3; i < result.size() / 3 * 2; ++i)
            {
                result[i].push_back('k');
            }
            for (int i = result.size() / 3 * 2; i < result.size(); ++i)
            {
                result[i].push_back('l');
            }
        }
        else if (digits[index] == '6')
        {
            for (int i = 0; i < result.size() / 3; ++i)
            {
                result[i].push_back('m');
            }
            for (int i = result.size() / 3; i < result.size() / 3 * 2; ++i)
            {
                result[i].push_back('n');
            }
            for (int i = result.size() / 3 * 2; i < result.size(); ++i)
            {
                result[i].push_back('o');
            }
        }
        else if (digits[index] == '7')
        {
            for (int i = 0; i < result.size() / 4; ++i)
            {
                result[i].push_back('p');
            }
            for (int i = result.size() / 4; i < result.size() / 2; ++i)
            {
                result[i].push_back('q');
            }
            for (int i = result.size() / 2; i < result.size() / 4 * 3; ++i)
            {
                result[i].push_back('r');
            }
            for (int i = result.size() / 4 * 3; i < result.size(); ++i)
            {
                result[i].push_back('s');
            }
        }
        else if (digits[index] == '8')
        {
            for (int i = 0; i < result.size() / 3; ++i)
            {
                result[i].push_back('t');
            }
            for (int i = result.size() / 3; i < result.size() / 3 * 2; ++i)
            {
                result[i].push_back('u');
            }
            for (int i = result.size() / 3 * 2; i < result.size(); ++i)
            {
                result[i].push_back('v');
            }
        }
        else if (digits[index] == '9')
        {
            for (int i = 0; i < result.size() / 4; ++i)
            {
                result[i].push_back('w');
            }
            for (int i = result.size() / 4; i < result.size() / 2; ++i)
            {
                result[i].push_back('x');
            }
            for (int i = result.size() / 2; i < result.size() / 4 * 3; ++i)
            {
                result[i].push_back('y');
            }
            for (int i = result.size() / 4 * 3; i < result.size(); ++i)
            {
                result[i].push_back('z');
            }
        }

        return result;
    }
};