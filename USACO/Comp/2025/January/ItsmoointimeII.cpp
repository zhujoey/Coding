#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int distinctNums(std::vector<int> nums, int avoid)
{
    std::unordered_set<int> findDistinct = {};

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != avoid)
        {
            findDistinct.insert(nums[i]);
        }
    }

    return findDistinct.size();
}

void findmoos(std::vector<int> nums)
{
    std::vector<int> original = nums;
    std::vector<int> repeats = {};
    std::sort(nums.begin(), nums.end());
    int currentnum = 0;
    int answer = 0;

    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] == nums[i + 1] && nums[i] != currentnum)
        {
            currentnum = nums[i];
            repeats.push_back(currentnum);
        }
    }

    bool shouldContinue = true;

    for (int i = 0; i < repeats.size(); ++i)
    {
        shouldContinue = true;
        for (int j = original.size() - 1; j >= 0; --j)
        {
            if (repeats[i] == original[j])
            {
                if (shouldContinue)
                {
                    shouldContinue = false;
                }
                else
                {
                    answer += distinctNums(std::vector<int>(original.begin(), original.begin() + j), repeats[i]);
                    break;
                }
            }
        }
    }

    std::cout << answer;
}

int main()
{
    int size = 0;
    int num = 0;
    std::vector<int> nums = {};

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> num;
        nums.push_back(num);
    }

    findmoos(nums);

    return 0;
}