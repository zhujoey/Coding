#include <iostream>
#include <set>

int main()
{
    long long t, n, h[200000];
    std::set<long long> ans;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        ans.clear();
        for (int i = 0; i < n; ++i)
        {
            std::cin >> h[i];
        }
        if (n == 2)
        {
            if (h[0] == h[1])
            {
                std::cout << h[0] << "\n";
            }
            else
            {
                std::cout << -1 << "\n";
            }
            continue;
        }
        for (int i = 0; i < n - 2; ++i)
        {
            if (h[i] == h[i + 1] || h[i] == h[i + 2])
            {
                ans.insert(h[i]);
            }
        }
        bool first = true;
        for (long long i : ans)
        {
            if (!first)
            {
                std::cout << " ";
            }
            std::cout << i;
            first = false;
        }
        if (ans.empty())
        {
            std::cout << -1;
        }
        std::cout << "\n";
    }
    return 0;
}