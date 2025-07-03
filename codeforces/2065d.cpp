#include <iostream>
#include <vector>
#include <algorithm>

long long findScore(std::vector<long long> nums)
{
    long long score = 0, prefix = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefix += nums[i];
        score += prefix;
    }
    return score;
}

long long findSum(std::vector<long long> nums)
{
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

int main()
{
    long long t, n, m, temp;
    std::vector<std::pair<long long, int>> scores;
    std::vector<std::vector<long long>> nums;
    std::vector<long long> tempNums;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        nums = {};
        scores = {};
        for (int i = 0; i < n; ++i)
        {
            tempNums = {};
            for (int j = 0; j < m; ++j)
            {
                std::cin >> temp;
                tempNums.push_back(temp);
            }
            nums.push_back(tempNums);
        }
        for (int i = 0; i < n; ++i)
        {
            scores.push_back({findSum(nums[i]), i});
        }
        std::sort(scores.rbegin(), scores.rend());
        tempNums = {};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                tempNums.push_back(nums[scores[i].second][j]);
            }
        }
        std::cout << findScore(tempNums) << "\n";
    }
    return 0;
}