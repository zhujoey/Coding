#include <iostream>

int main()
{
    long long n = 0, m = 0, u = 0, v = 0, w = 0, cycle = 0, min_cycle = 100000000000LL,
              adj[105][105] = { 0 }, dist[105][105] = { 0 };

    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                adj[i][j] = 0;
                dist[i][j] = 0;
            }
            else
            {
                adj[i][j] = 1000000000;
                dist[i][j] = 1000000000;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> u >> v >> w;
        if (w < adj[u][v])
        {
            adj[u][v] = adj[v][u] = w;
        }
        if (w < dist[u][v])
        {
            dist[u][v] = dist[v][u] = w;
        }
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i < k; ++i)
        {
            for (int j = i + 1; j < k; ++j)
            {
                cycle = dist[i][j] + adj[i][k] + adj[k][j];
                if (cycle < min_cycle)
                {
                    min_cycle = cycle;
                }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    if (min_cycle == 100000000000LL)
    {
        std::cout << "No solution." << std::endl;
    }
    else
    {
        std::cout << min_cycle << std::endl;
    }

    return 0;
}