#include <iostream>
#include <vector>
#include <algorithm>
 
int main()
{
    int t, n, i, u, v, x, y;
    std::vector<int> a, b;
    std::vector<std::pair<int, int>> pairsa, pairsb;
 
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
 
        a.resize(n);
        for (i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
 
        b.resize(n);
        for (i = 0; i < n; i++)
        {
            std::cin >> b[i];
        }
 
        if (n % 2 != 0)
        {
            if (a[n / 2] != b[n / 2])
            {
                std::cout << "No\n";
                continue;
            }
        }
 
        pairsa.clear();
        pairsb.clear();
 
        for (i = 0; i < n / 2; i++)
        {
            u = a[i];
            v = a[n - 1 - i];
            if (u > v)
            {
                std::swap(u, v);
            }
            pairsa.push_back({u, v});
 
            x = b[i];
            y = b[n - 1 - i];
            if (x > y)
            {
                std::swap(x, y);
            }
            pairsb.push_back({x, y});
        }
 
        std::sort(pairsa.begin(), pairsa.end());
        std::sort(pairsb.begin(), pairsb.end());
 
        if (pairsa == pairsb)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
 
    return 0;
}