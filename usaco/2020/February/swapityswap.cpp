
#include <iostream>
#include <string>

int main()
{
    int n, k, a1, a2, b1, b2, p, cur, steps, res[101];

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    std::cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    for (int i = 1; i <= n; i++)
    {
        p = 1;

        cur = i;
        if (a1 <= cur && cur <= a2)
        {
            cur = a1 + a2 - cur;
        }
        if (b1 <= cur && cur <= b2)
        {
            cur = b1 + b2 - cur;
        }

        while (cur != i)
        {
            p++;

            if (a1 <= cur && cur <= a2)
            {
                cur = a1 + a2 - cur;
            }
            if (b1 <= cur && cur <= b2)
            {
                cur = b1 + b2 - cur;
            }
        }

        steps = k % p;
        for (int j = 0; j < steps; j++)
        {
            if (a1 <= cur && cur <= a2)
            {
                cur = a1 + a2 - cur;
            }
            if (b1 <= cur && cur <= b2)
            {
                cur = b1 + b2 - cur;
            }
        }

        res[cur] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << res[i] << '\n';
    }

    return 0;
}
