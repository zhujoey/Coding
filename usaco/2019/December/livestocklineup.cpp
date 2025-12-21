#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

int main()
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int n, pos;
    bool valid;
    std::pair<std::string, std::string> next[7];
    std::string cows[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> next[i].first >> next[i].second >> next[i].second >> next[i].second >> next[i].second >> next[i].second;
    }
    while (true)
    {
        valid = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (next[i].first == cows[j])
                {
                    pos = j;
                }
            }
            for (int j = 0; j < 8; ++j)
            {
                if (next[i].second == cows[j])
                {
                    if (j - pos != 1 && pos - j != 1)
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid)
            {
                break;
            }
        }
        if (valid)
        {
            for (int i= 0; i < 8; ++i)
            {
                std::cout << cows[i] << "\n";
            }
            break;
        }
        next_permutation(cows, cows + 8);
    }
    return 0;
}