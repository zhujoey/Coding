#include <iostream>
#include <vector>

int n = 0, totalred = 0, totalblue = 0, niceedges = 0;
std::vector<int> colors;
std::vector<std::vector<int>> adj;

std::pair<int, int> dfs(int u, int p) 
{
    int rcount = (colors[u] == 1), bcount = (colors[u] == 2), subr = 0, subb = 0;

    for (int v : adj[u]) 
    {
        if (v != p) 
        {
            std::tie(subr, subb) = dfs(v, u);
            
            if ((subr == totalred && subb == 0) || (subr == 0 && subb == totalblue)) 
            {
                niceedges++;
            }

            rcount += subr;
            bcount += subb;
        }
    }

    return {rcount, bcount};
}

int main() 
{
    int u = 0, v = 0;

    if (!(std::cin >> n)) 
    {
        return 0;
    }

    colors.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) 
    {
        std::cin >> colors[i];
        if (colors[i] == 1) 
        {
            totalred++;
        }
        if (colors[i] == 2) 
        {
            totalblue++;
        }
    }

    for (int i = 0; i < n - 1; ++i) 
    {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    std::cout << niceedges << "\n";

    return 0;
}