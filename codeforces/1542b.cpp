#include <iostream>

int main()
{
    long long t, n, a, b, x;
    std::cin >> t;
    bool ok = false;

    while (t--)
    {
        std::cin >> n >> a >> b;
        ok = false;
        x = 1;

        if (a == 1)
        {
            if ((n - 1) % b == 0)
            {
                ok = true;
            }
        }
        else
        {
            while (x <= n)
            {
                if ((n - x) % b == 0)
                {
                    ok = true;
                    break;
                }
                x *= a;
            }
        }

        if (ok)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}