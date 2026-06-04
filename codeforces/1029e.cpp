#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, first, second;
    if (!(std::cin >> n))
    {
        return 0;
    }

    std::vector<std::vector<long long>> adj(n + 1);
    std::vector<long long> dist(n + 1, -1);
    std::vector<long long> parent(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    std::queue<long long> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        long long curr = q.front();
        q.pop();

        for (int i = 0; i < adj[curr].size(); ++i)
        {
            long long neighbor = adj[curr][i];
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[curr] + 1;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    std::vector<std::pair<long long, long long>> deep_nodes;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > 2)
        {
            deep_nodes.push_back({dist[i], i});
        }
    }
    
    std::sort(deep_nodes.rbegin(), deep_nodes.rend());

    std::vector<bool> covered(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] <= 2)
        {
            covered[i] = true;
        }
    }

    long long added_edges = 0;

    for (int i = 0; i < deep_nodes.size(); i++)
    {
        long long u = deep_nodes[i].second;
        
        if (covered[u])
        {
            continue;
        }

        long long p = parent[u];
        added_edges++;

        covered[p] = true;
        for (int j = 0; j < adj[p].size(); j++)
        {
            covered[adj[p][j]] = true;
        }
        covered[parent[p]] = true;
    }

    std::cout << added_edges << "\n";

    return 0;
}