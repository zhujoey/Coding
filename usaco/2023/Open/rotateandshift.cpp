#include <iostream>

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    long long n, k, t, a[200005], ans[200005], vals[200005];
    std::cin >> n >> k >> t;

    for (int j = 1; j <= k; j++)
    {
        std::cin >> a[j];
    }

    for (int j = 0; j < n; j++)
    {
        ans[j] = j;
    }

    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            vals[j - 1] = ans[a[j]];
        }
        
        for (int j = 1; j <= k; j++)
        {
            ans[a[j]] = vals[(j - 2 + k) % k];
        }

        for (int j = 1; j <= k; j++)
        {
            a[j] = (a[j] + 1) % n;
        }
    }

    for (int j = 0; j < n; j++)
    {
        std::cout << ans[j];
        if (j + 1 < n)
        {
            std::cout << " ";
        }
    }

    std::cout << "\n";
    return 0;
}