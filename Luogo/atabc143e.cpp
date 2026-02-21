#include <iostream>

int main()
{
    long long dist[305][305] = {}, refuel[305][305] = {}, n = 0, m = 0, l = 0, a = 0, b = 0, c = 0, k = 0, q = 0, s = 0, t = 0;

    std::cin >> n >> m >> l;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = 1000000007;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> c;
        a -= 1;
        b -= 1;
        if (c <= l)
        {
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for (k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                refuel[i][j] = 0;
            }
            else if (dist[i][j] <= l)
            {
                refuel[i][j] = 1;
            }
            else
            {
                refuel[i][j] = 1000000007;
            }
        }
    }

    for (k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (refuel[i][k] + refuel[k][j] < refuel[i][j])
                {
                    refuel[i][j] = refuel[i][k] + refuel[k][j];
                }
            }
        }
    }

    std::cin >> q;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> s >> t;
        s -= 1;
        t -= 1;
        if (refuel[s][t] == 1000000007)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << refuel[s][t] - 1 << std::endl;
        }
    }

    return 0;
}