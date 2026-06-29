#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, s = 0, i, a, b, leaves, cur, par, sum, u, next;

    std::cin >> n;

    std::vector<int> pots(n, 0), numleaves(n, 0), modpots(n, 0), parent(n, -1), order, leafcount(n, 0), potionsum(n, 0);
    std::vector<std::vector<int>> graph(n);

    for (i = 0; i < n; i++)
    {
        std::cin >> pots[i];
        pots[i]--;
    }
    for (i = 0; i < n - 1; i++)
    {
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> stack;
    stack.push_back(s);
    while (!stack.empty())
    {
        cur = stack.back();
        stack.pop_back();
        order.push_back(cur);
        for (i = 0; i < int(graph[cur].size()); i++)
        {
            next = graph[cur][i];
            if (next != parent[cur])
            {
                parent[next] = cur;
                stack.push_back(next);
            }
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        cur = order[i];
        if (cur != s && graph[cur].size() == 1)
        {
            numleaves[cur] = 1;
        }
        else
        {
            sum = 0;
            for (u = 0; u < int(graph[cur].size()); u++)
            {
                next = graph[cur][u];
                if (next != parent[cur])
                {
                    sum += numleaves[next];
                }
            }
            numleaves[cur] = sum;
        }
    }

    leaves = numleaves[s];
    for (i = 0; i < leaves; i++)
    {
        modpots[pots[i]]++;
    }

    for (i = n - 1; i >= 0; i--)
    {
        cur = order[i];
        sum = 0;
        for (u = 0; u < int(graph[cur].size()); u++)
        {
            next = graph[cur][u];
            if (next != parent[cur])
            {
                sum += potionsum[next];
            }
        }
        sum += modpots[cur];
        potionsum[cur] = std::min(sum, numleaves[cur]);
    }

    std::cout << potionsum[s] << std::endl;
}