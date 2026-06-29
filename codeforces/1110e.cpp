#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    if (!(std::cin >> n))
    {
        return 0;
    }

    std::vector<long long> c(n), t(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> t[i];
    }

    if (c[0] != t[0] || c[n - 1] != t[n - 1])
    {
        std::cout << "No\n";
        return 0;
    }

    std::vector<long long> gdiff(n - 1), adiff(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        gdiff[i] = c[i + 1] - c[i];
        adiff[i] = t[i + 1] - t[i];
    }

    std::sort(gdiff.begin(), gdiff.end());
    std::sort(adiff.begin(), adiff.end());

    if (gdiff == adiff)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}