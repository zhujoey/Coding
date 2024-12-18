#include <iostream>
#include <vector>

int count(const int &num)
{
    int result = 0;
    int current = 0;
    std::vector<int> digits = {};

    if (num < 2)
    {
        return 0;
    }

    for (int i = 2; i <= num; ++i)
    {
        digits = {};
        
        current = i;

        while (current > 0)
        {
            digits.push_back(current % 10);
            current /= 10;
        }

        for (int j = digits.size() - 1; j >= 0; --j)
        {
            if (j == digits.size() - 1 && digits[j] != 4)
            {
                break;
            }
            else if (digits[j] < 4)
            {
                break;
            }
            else if (digits[j] > 4)
            {
                ++result;
                break;
            }
        }
    }

    return result;
}

int main()
{
    int inputcount = 0;
    int currentinput = 0;
    std::cin >> inputcount;

    for (int i = 0; i < inputcount; ++i)
    {
        std::cin >> currentinput;
        std::cout << count(currentinput) << std::endl;;
    }

    return 0;
};