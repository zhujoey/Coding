#include <iostream>
#include <utility>
#include <algorithm>

int main()
{
    int m, s, c, a[200], ans;
    std::pair<int, int> diff[199];
    std::cin >> m >> s >> c;
    for (int i = 0; i < c; ++i)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + c);
    ans = a[c - 1] - a[0] + 1;

    for (int i = 1; i < c; ++i)
    {
        diff[i - 1].first = a[i] - a[i - 1] - 1;
        diff[i - 1].second = 0;
    }

    std::sort(diff, diff + c - 1, [](auto &a, auto &b)
    {
        return a.first > b.first;
    });

    for (int i = 0; i < m - 1; ++i)
    {
        ans -= diff[i].first;
    }
    std::cout << ans;
    return 0;
}