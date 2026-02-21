#include <iostream>

int main()
{
    long long dist[205][205] = {}, rebuild[205] = {}, n = 0, m = 0, q = 0, u = 0, v = 0, w = 0, x = 0, y = 0, t = 0, unlocked = 0;

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> rebuild[i];
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = 1000000000;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    std::cin >> q;

    for (int i = 0; i < q; ++i)
    {
        std::cin >> x >> y >> t;

        while (unlocked < n && rebuild[unlocked] <= t)
        {
            for (int a = 0; a < n; ++a)
            {
                for (int b = 0; b < n; ++b)
                {
                    if (dist[a][unlocked] + dist[unlocked][b] < dist[a][b])
                    {
                        dist[a][b] = dist[a][unlocked] + dist[unlocked][b];
                    }
                }
            }
            unlocked += 1;
        }

        if (rebuild[x] > t || rebuild[y] > t || dist[x][y] == 1000000000)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << dist[x][y] << std::endl;
        }
    }

    return 0;
}