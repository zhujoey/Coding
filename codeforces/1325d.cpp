#include <iostream>

int main()
{
    long long u, v, a, x, y;
    std::cin >> u >> v;

    if (u > v || (u % 2 != v % 2))
    {
        std::cout << -1;
        return 0;
    }

    if (u == v)
    {
        if (u == 0)
            std::cout << "0";
        else
            std::cout << "1\n" << u;
        return 0;
    }

    a = (v - u) / 2;
    x = a;
    y = v - a;

    if ((x ^ y) == u)
    {
        std::cout << "2\n" << x << " " << y;
    }
    else
    {
        std::cout << "3\n" << a << " " << a << " " << u;
    }

    return 0;
}