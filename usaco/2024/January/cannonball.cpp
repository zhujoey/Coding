#include <iostream>
#include <utility>
#include <vector>

int main()
{
    long long n, s, dir = 1, power = 1, ans = 0;
    std::cin >> n >> s;
    std::vector<std::pair<int, int>> pad(n + 1);
    std::vector<bool> broke(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> pad[i].first >> pad[i].second;
    }
    for (int i = 0; i < 5000000 && s >= 1 && s <= n; ++i)
    {
        if (pad[s].first == 1 && power >= pad[s].second && !broke[s])
        {
            broke[s] = true;
            ++ans;
        }
        if (pad[s].first == 0)
        {
            dir *= -1;
            power += pad[s].second;
        }
        s += dir * power;
    }
    std::cout << ans;
    return 0;
}