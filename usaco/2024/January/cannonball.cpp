#include <iostream>
#include <vector>
#include <utility>

int main()
{
    long long n, s, dir = 1, k = 1, ans = 0;
    std::cin >> n >> s;
    std::vector<std::pair<int, int>> spot(n + 1);
    std::vector<bool> broke(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> spot[i].first >> spot[i].second;
    }
    for (int i = 0; i < 5000000 && s >= 1 && s <= n; ++i)
    {
        if (spot[s].first == 1 && k >= spot[s].second && !broke[s])
        {
            broke[s] = true;
            ++ans;
        }
        if (spot[s].first == 0)
        {
            dir *= -1;
            k += spot[s].second;
        }
        s += dir * k;
    }
    std::cout << ans;
    return 0;
}