#include <iostream>
#include <utility>

int main()
{
    long long n = 0, m = 0, d = 0, a = 0, b = 0, u = 0, v = 0, w = 0, k = 0;
    std::pair<long long, long long> road[101][101];

    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 100; ++j)
        {
            road[i][j] = std::make_pair(1000000000000000000, 1000000000000000000);
        }
    }

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        std::cin >> u >> v >> w;
        road[u][v].first = w;
        road[v][u].first = w;
        road[u][v].second = 0;
        road[v][u].second = 0;
    }

    std::cin >> d;

    for (int i = 0; i < d; ++i)
    {
        std::cin >> u >> v;
        road[u][v].second = road[u][v].first;
        road[v][u].second = road[v][u].first;
    }

    std::cin >> a >> b;

    for (k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                long long new_cost = road[i][k].first + road[k][j].first;
                long long new_repair = road[i][k].second + road[k][j].second;

                if (new_cost < road[i][j].first)
                {
                    road[i][j].first = new_cost;
                    road[i][j].second = new_repair;
                }
                else if (new_cost == road[i][j].first && new_repair < road[i][j].second)
                {
                    road[i][j].second = new_repair;
                }
            }
        }
    }

    if (road[a][b].first == 1000000000000000000)
    {
        std::cout << "No solution.\n";
    }
    else
    {
        std::cout << road[a][b].second << "\n";
    }

    return 0;
}