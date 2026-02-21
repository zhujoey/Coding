#include <iostream>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n >> m;
    long long a[200000], pref[200001], ans[200001];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n);

    pref[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    for (int k = 1; k <= n; ++k)
    {
        ans[k] = pref[k];
        if (k > m)
        {
            ans[k] += ans[k - m];
        }
        std::cout << ans[k] << " ";
    }
    return 0;
}