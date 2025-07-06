#include <iostream>

int main()
{
    int t, n, x[200000], y[200000], prev, zi;

    std::cin >> t;

    while (t--)
    {
        std::cin >> n;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> x[i];
        }

        prev = 0;

        for (int i = 0; i < n; ++i)
        {
            zi = x[i] | prev;
            y[i] = x[i] ^ zi;
            prev = zi;
        }

        for (int i = 0; i < n; ++i)
        {
            std::cout << y[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}