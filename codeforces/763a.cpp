#include <iostream>
#include <vector>

bool checkcandidate(int candidate, int n, const std::vector<std::pair<int, int>>& edges, const std::vector<int>& color)
{
    int i, u, v;
    for (i = 0; i < n - 1; ++i)
    {
        u = edges[i].first;
        v = edges[i].second;
        if (color[u] != color[v])
        {
            if (u != candidate && v != candidate)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, i, u, v, rootone = -1, roottwo = -1;
    std::cin >> n;

    std::vector<std::pair<int, int>> edges(n - 1);
    for (i = 0; i < n - 1; ++i)
    {
        std::cin >> edges[i].first >> edges[i].second;
    }

    std::vector<int> color(n + 1);
    for (i = 1; i <= n; ++i)
    {
        std::cin >> color[i];
    }

    for (i = 0; i < n - 1; ++i)
    {
        u = edges[i].first;
        v = edges[i].second;
        if (color[u] != color[v])
        {
            rootone = u;
            roottwo = v;
            break;
        }
    }

    if (rootone == -1)
    {
        std::cout << "YES\n1\n";
        return 0;
    }

    if (checkcandidate(rootone, n, edges, color))
    {
        std::cout << "YES\n" << rootone << "\n";
    }
    else if (checkcandidate(roottwo, n, edges, color))
    {
        std::cout << "YES\n" << roottwo << "\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}1332