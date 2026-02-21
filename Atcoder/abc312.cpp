#include <iostream>
#include <algorithm>

long long n, m, a[200005], b[200005];

int main()
{
    long long x, l = 1, r = 1000000001, c, d, ans = 1000000001;

    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    if (!(std::cin >> n >> m))
    {
        return 0;
    }
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }

    std::sort(a, a + n);
    std::sort(b, b + m);

    while (r >= l)
    {
        x = l + (r - l) / 2;
        c = std::upper_bound(a, a + n, x) - a;
        d = m - (std::lower_bound(b, b + m, x) - b);
        
        if (c < d)
        {
            l = x + 1;
        }
        else
        {
            ans = x;
            r = x - 1;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}