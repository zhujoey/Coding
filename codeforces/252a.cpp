#include <iostream>

int main()
{
    int n, a[100], ans = 0, current;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            current = a[i];
            for (int k = i + 1; k <= j; ++k)
            {
                current ^= a[k];
            }
            if (current > ans)
            {
                ans = current;
            }
        }
    }
    std::cout << ans;
    return 0;
}