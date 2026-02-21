#include <iostream>
#include <algorithm>

int main()
{
    int n, a, b[100000], d[100000], ans[100000];
    bool used[100000], bad;
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);


    std::cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> b[i];
    }

    for (int i = 2; i < n; i++)
    {
        d[i] = b[i - 1] - b[i - 2];
    }

    for (a = 1; a <= n; a++)
    {
        ans[0] = a;
        ans[1] = b[0] - a;

        for (int i = 2; i < n; i++)
        {
            ans[i] = ans[i - 2] + d[i];
        }

        for (int i = 1; i <= n; i++)
        {
            used[i] = false;
        }

        bad = false;

        for (int i = 0; i < n; i++)
        {
            if (used[ans[i]] || ans[i] <= 0 || ans[i] > n)
            {
                bad = true;
                break;
            }
            used[ans[i]] = true;
        }

        if (!bad)
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << ans[i];
                if (i < n - 1)
                {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
            return 0;
        }
    }

    return 0;
}