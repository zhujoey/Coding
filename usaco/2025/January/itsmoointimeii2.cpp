#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    long long n, ans = 0;
    std::cin >> n;
    std::vector<long long> a(n);
    std::vector<long long> first(n + 1, -1);
    std::vector<long long> cnt(n + 1, 0);
    std::vector<long long> sorted;

    for (long long i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if (first[a[i]] == -1)
        {
            first[a[i]] = i;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (first[i] != -1) {
            sorted.push_back(first[i]);
        }
    }

    std::sort(sorted.begin(), sorted.end());

    for (long long i = n - 1; i >= 0; --i)
    {
        if (a[i] < n)
        {
            ++cnt[a[i]];
            if (cnt[a[i]] == 2)
            {
                ans += std::lower_bound(sorted.begin(), sorted.end(), i) - sorted.begin();
            }
        }
    }

    for (long long i = 1; i <= n; ++i)
    {
        if (cnt[i] >= 3)
        {
            --ans;
        }
    }

    std::cout << ans;
    return 0;
}