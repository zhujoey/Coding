#include <iostream>
#include <algorithm>

int main()
{
    int t, n, m, a[200000], b[200000], prev;
    bool skip = false;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        std::cin >> n >> m;
        for (int j = 0; j < n; ++j)
        {
            std::cin >> a[j];
        }
        std::cin >> m;
        for (int j = 0; j < n; ++j)
        {
            b[j] = m - a[j];
        }
        prev = std::min(a[0], b[0]);
        skip = false;
        for (int j = 1; j < n; ++j)
        {
            if (a[j] >= prev)
            {
                if (b[j] >= prev)
                {
                    prev = std::min(a[j], b[j]);
                }
                else
                {
                    prev = a[j];
                }
            }
            else
            {
                if (b[j] >= prev)
                {
                    prev = b[j];
                }
                else
                {
                    std::cout << "NO\n";
                    skip = true;
                    break;
                }
            }
        }
        if (!skip)
        {
            std::cout << "YES\n";
        }
    }
    return 0;
}