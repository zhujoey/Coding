#include <functional>
#include <iostream>
#include <algorithm>

int n, q, diffs[1000000], t, v, s;

int main()
{
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> diffs[i];
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> t;
        diffs[i] -= t;
    }

    std::sort(diffs, diffs + n, std::greater<int>());

    for (int i = 0; i < q; ++i)
    {
        std::cin >> v >> s;
        if (diffs[v - 1] > s)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
    
    return 0;
}