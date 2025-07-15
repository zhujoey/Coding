#include <iostream>
#include <algorithm>

int main()
{
    int a[100000], p[100000], b[100000], c[100000], n, l, r, minBase, maxBase;
    std::cin >> n >> l >> r;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
    }

    minBase = l - a[0] - (p[0] - 1);
    maxBase = r - a[0] - (p[0] - 1);

    for (int i = 1; i < n; ++i)
    {
        minBase = std::max(minBase, l - a[i] - (p[i] - 1));
        maxBase = std::min(maxBase, r - a[i] - (p[i] - 1));
    }

    if (minBase > maxBase)
    {
        std::cout << -1 << std::endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        c[i] = minBase + (p[i] - 1);
        b[i] = a[i] + c[i];
        std::cout << b[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}