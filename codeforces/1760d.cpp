#include <iostream>
#include <vector>

int main()
{
    int t, n, valleys, i, j, a[200000];
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        valleys = 0;

        for (i = 0; i < n; ++i)
        {
            j = i;

            while (j + 1 < n && a[j] == a[j + 1])
            {
                ++j;
            }

            if ((i == 0 || a[i - 1] > a[i]) && (j == n - 1 || a[j + 1] > a[j]))
            {
                ++valleys;
            }

            if (valleys > 1)
            {
                std::cout << "NO\n";
                break;
            }

            i = j;
        }

        if (valleys == 1)
        {
            std::cout << "YES\n";
        }
        else if (valleys == 0)
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}