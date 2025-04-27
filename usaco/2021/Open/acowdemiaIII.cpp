#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

int n, m, ans = 0;
std::array<std::string, 1001> field;
std::pair<int, int> coords;
std::vector<std::pair<int, int>> cows;
std::set<std::vector<std::pair<int, int>>> pairs;

int main()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> field[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cows = {};

            if (field[i][j] != 'G')
            {
                continue;
            }

            if (i > 0 && field[i - 1][j] == 'C')
            {
                coords = {i - 1, j};
                cows.push_back(coords);
            }
            if (i < n - 1 && field[i + 1][j] == 'C')
            {
                coords = {i + 1, j};
                cows.push_back(coords);
            }
            if (j > 0 && field[i][j - 1] == 'C')
            {
                coords = {i, j - 1};
                cows.push_back(coords);
            }
            if (j < m - 1 && field[i][j + 1] == 'C')
            {
                coords = {i, j + 1};
                cows.push_back(coords);
            }

            if (cows.size() > 2)
            {
                ++ans;
            }
            else if (cows.size() == 2)
            {
				std::sort(cows.begin(), cows.end());
                pairs.insert(cows);
            }
        }
    }

    std::cout << ans + pairs.size();

    return 0;
}