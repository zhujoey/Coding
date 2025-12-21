#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n, ans = 0;
    std::cin >> n;
    std::pair<int, int> coords[100];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> coords[i].first >> coords[i].second;
    }
    for (int a = 0; a < n; ++ a)
    {
        for (int b = 0; b < n; ++b)
        {
            if (b == a || coords[b].first != coords[a].first)
            {
                continue;
            }
            for (int c = 0; c < n; ++c)
            {
                if (c == a || c == b || coords[c].second != coords[a].second)
                {
                    continue;
                }
                ans = std::max(ans, std::abs((coords[b].second - coords[a].second) * (coords[c].first - coords[a].first)));
            }
        }
    }
    std::cout << ans;
    return 0;
}