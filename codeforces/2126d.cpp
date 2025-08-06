#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t, n;
    long long k, maxCoins;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> k;
        std::vector<std::tuple<int, int, int>> casinos(n);
        for (int i = 0; i < n; i++)
        {
            int li, ri, reali;
            std::cin >> li >> ri >> reali;
            casinos[i] = std::make_tuple(li, ri, reali);
        }
        std::sort(casinos.begin(), casinos.end(), [](const auto &a, const auto &b)
        {
            return std::get<0>(a) < std::get<0>(b);
        });
        
        maxCoins = k;
        for (int i = 0; i < n; i++)
        {
            int li = std::get<0>(casinos[i]);
            int ri = std::get<1>(casinos[i]);
            int reali = std::get<2>(casinos[i]);
            if (li <= maxCoins && maxCoins <= ri)
            {
                maxCoins = std::max(maxCoins, (long long)reali);
            }
            else if (maxCoins < li)
            {
                break;
            }
        }
        std::cout << maxCoins << std::endl;
    }
    return 0;
}
