#include <iostream>
#include <algorithm>

int main()
{
    long long prefix = 0, n, a[200000], ans = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        ans += a[i] * i - prefix;
        prefix += a[i];
    }
    std::cout << ans;
}