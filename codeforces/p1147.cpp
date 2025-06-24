#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
    int m;
    std::cin >> m;

    std::vector<std::pair<int, int>> results;

    for (int k = 2; k * (k - 1) / 2 < m; ++k)
    {
        int top = 2 * m - k * (k - 1);
        if (top % (2 * k) == 0)
        {
            int a = top / (2 * k);
            if (a > 0)
            {
                results.push_back({a, a + k - 1});
            }
        }
    }

    std::sort(results.begin(), results.end());

    for (auto &p : results)
    {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}