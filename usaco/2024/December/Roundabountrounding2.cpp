#include <iostream>
#include <vector>

int add(const int start, int count, const int num)
{
    std::vector<int> digits = {};
    int current = 0;

    if (num <= 2)
    {
        return 0;
    }
    else if (start > num)
    {
        for (int i = start; i > num; --i)
        {
            digits.clear();
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
                    --count;
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = start + 1; i <= num; ++i)
        {
            digits.clear();
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
                    ++count;
                    break;
                }
            }
        }
    }

    return count;
}

void count(std::vector<int> nums)
{
    int previouscount = 0;
    int previousnum = 2;

    for (int i = 0; i < nums.size(); ++i)
    {
        previouscount = add(previousnum, previouscount, nums[i]);
        std::cout << previouscount << std::endl;
        previousnum = nums[i];
    }
}

int main()
{
    int inputcount = 0;
    int currentinput = 0;
    std::vector<int> inputs = {};
    std::cin >> inputcount;

    for (int i = 0; i < inputcount; ++i)
    {
        std::cin >> currentinput;
        inputs.push_back(currentinput);
    }

    count(inputs);

    return 0;
};