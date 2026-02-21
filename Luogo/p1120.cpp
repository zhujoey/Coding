#include <iostream>
#include <algorithm>
#include <vector>

bool dfs(std::vector<long long>& a, long long goal, std::vector<std::vector<long long>>& groups, long long i, long long n)
{
    long long sum = 0, end = 0;
    bool result = false;

    if (i == n)
    {
        return true;
    }

    for (int x = 0; x < groups.size(); ++x)
    {
        sum = 0;
        end = 0;

        for (int y = 0; y < groups[x].size(); ++y)
        {
            sum += groups[x][y];
            if (groups[x][y] == 0)
            {
                end = y;
                break;
            }
        }

        if (sum + a[i] <= goal)
        {
            if (end == groups[x].size())
            {
                groups[x].push_back(a[i]);
            }
            else
            {
                groups[x][end] = a[i];
            }

            result = dfs(a, goal, groups, i + 1, n);
            if (result)
            {
                return true;
            }

            if (end == groups[x].size() - 1)
            {
                groups[x].pop_back();
            }
            else
            {
                groups[x][end] = 0;
            }
        }
    }

    return false;
}

int main()
{
    long long n = 0, sum = 0, longest = 0, groupcount = 0, value;
    bool success;
    std::vector<long long> a;
    std::vector<std::vector<long long>> groups;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        value = 0;
        std::cin >> value;
        a.push_back(value);
        sum += value;
        if (value > longest)
        {
            longest = value;
        }
    }

    std::sort(a.begin(), a.end(), std::greater<long long>());

    for (int i = longest; i <= sum; ++i)
    {
        if (sum % i != 0)
        {
            continue;
        }

        groupcount = sum / i;
        groups.clear();

        for (int j = 0; j < groupcount; ++j)
        {
            groups.push_back(std::vector<long long>());
        }

        success = dfs(a, i, groups, 0, n);
        if (success)
        {
            std::cout << i;
            return 0;
        }
    }

    return 0;
}