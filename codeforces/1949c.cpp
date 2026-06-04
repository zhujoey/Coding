#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n = 0, u = 0, v = 0, elimnodes = 0, curr = 0, neighbor = 0, nextneigh = 0;
    std::vector<std::vector<int>> adj, waiting;
    std::vector<int> degree, ants;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<bool> removed, inqueue;

    if (!(std::cin >> n)) 
    {
        return 0;
    }

    if (n == 1) 
    {
        std::cout << "YES\n";
        return 0;
    }

    adj.resize(n + 1);
    waiting.resize(n + 1);
    degree.assign(n + 1, 0);
    ants.assign(n + 1, 1);
    removed.assign(n + 1, false);
    inqueue.assign(n + 1, false);

    for (int i = 0; i < n - 1; ++i) 
    {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    for (int i = 1; i <= n; ++i) 
    {
        if (degree[i] == 1) 
        {
            pq.push({ants[i], i});
            inqueue[i] = true;
        }
    }

    while (!pq.empty()) 
    {
        curr = pq.top().second;
        pq.pop();

        if (removed[curr] || degree[curr] != 1)
        {
            continue;
        }

        neighbor = 0;
        for (int nxt : adj[curr]) 
        {
            if (!removed[nxt]) 
            {
                neighbor = nxt;
                break;
            }
        }

        if (neighbor == 0)
        {
            continue;
        }

        if (ants[curr] <= ants[neighbor]) 
        {
            ants[neighbor] += ants[curr];
            elimnodes++;
            removed[curr] = true;
            degree[curr]--;
            degree[neighbor]--;

            if (degree[neighbor] == 1 && !inqueue[neighbor]) 
            {
                pq.push({ants[neighbor], neighbor});
                inqueue[neighbor] = true;
            }

            std::vector<int> remaining;
            for (int child : waiting[neighbor])
            {
                if (!removed[child])
                {
                    if (ants[child] <= ants[neighbor])
                    {
                        if (!inqueue[child])
                        {
                            pq.push({ants[child], child});
                            inqueue[child] = true;
                        }
                    }
                    else
                    {
                        remaining.push_back(child);
                    }
                }
            }
            waiting[neighbor] = remaining;
        }
        else
        {
            inqueue[curr] = false;
            waiting[neighbor].push_back(curr);
        }
    }

    if (elimnodes == n - 1) 
    {
        std::cout << "YES\n";
    } 
    else 
    {
        std::cout << "NO\n";
    }

    return 0;
}