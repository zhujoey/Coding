#include <iostream>

int head[100005], to[200010], nxt[200010], deg[100005], edgecnt = 0, n = 0, u = 0, v = 0, rootleaf = 1, minf = 0, maxf = 0, leavesattached = 0, neighbor = 0;
bool hasoddleaf = false, hasevenleaf = false;

void dfs(int u, int p, int d)
{
    int v = 0;

    if (deg[u] == 1)
    {
        if (d % 2 == 0)
        {
            hasevenleaf = true;
        }
        else
        {
            hasoddleaf = true;
        }
    }

    for (int e = head[u]; e; e = nxt[e])
    {
        v = to[e];
        if (v != p)
        {
            dfs(v, u, d + 1);
        }
    }
}

int main()
{
    std::cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> u >> v;
        
        edgecnt++;
        to[edgecnt] = v;
        nxt[edgecnt] = head[u];
        head[u] = edgecnt;
        deg[u]++;

        edgecnt++;
        to[edgecnt] = u;
        nxt[edgecnt] = head[v];
        head[v] = edgecnt;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1)
        {
            rootleaf = i;
            break;
        }
    }

    dfs(rootleaf, -1, 0);

    minf = (hasoddleaf && hasevenleaf) ? 3 : 1;
    maxf = n - 1;

    for (int i = 1; i <= n; i++)
    {
        leavesattached = 0;
        for (int e = head[i]; e; e = nxt[e])
        {
            neighbor = to[e];
            if (deg[neighbor] == 1)
            {
                leavesattached++;
            }
        }

        if (leavesattached > 1)
        {
            maxf -= leavesattached - 1;
        }
    }

    std::cout << minf << " " << maxf;

    return 0;
}1949c