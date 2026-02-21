#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

int main()
{
    long long n, h, ans = 0, need;
    std::vector<std::pair<std::pair<long long, long long>, long long>> bet;
    std::pair<std::pair<long long, long long>, long long> temp;

    std::cin >> n >> h;
    std::vector<long long> planted(n + 1, 0);
    std::vector<long long> pref(n + 1, 0);

    while (h--)
    {
        std::cin >> temp.first.first >> temp.first.second >> temp.second;
        bet.push_back(temp);
    }

    std::sort(bet.begin(), bet.end(), [](const auto &a, const auto &b)
    {
        return a.first.second < b.first.second;
    });

    for (int i = 0; i < bet.size(); ++i)
    {
        long long b = bet[i].first.first;
        long long e = bet[i].first.second;
        long long t = bet[i].second;
        need = t - pref[e] + pref[b - 1];

        for (long long pos = e; pos >= b && need > 0; --pos)
        {
            if (!planted[pos])
            {
                planted[pos] = 1;
                ++ans;
                --need;
                for (long long k = pos; k <= n; ++k)
                {
                    ++pref[k];
                }
            }
        }
    }

    std::cout << ans;
    return 0;
}