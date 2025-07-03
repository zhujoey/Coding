#include <iostream>
#include <numeric>

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        long long a, b, x;
        bool found = false;
        std::cin >> a >> b >> x;

        while (true)
        {
            if (a < b)
            {
                std::swap(a, b);
            }
            if (x > a && x > b || a == 0 || b == 0)
            {
                break;
            }
            if ((a - x) % b == 0 && x >= b || a == x || b == x)
            {
                found = true;
                break;
            }

            a = a % b;
        }

        if (found)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}