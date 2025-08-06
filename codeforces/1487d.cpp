#include <iostream>
#include <cmath>

int main()
{
    long long t = 0, count = 0, n = 0, limit = 0, a = 0, b = 0, c = 0;

    std::cin >> t;

    while (t--)
    {
        std::cin >> n;
        count = -1;
        limit = static_cast<long long>(sqrt(2 * n - 1));

        for (a = 1; a <= limit; a += 2)
        {
            b = (a * a - 1) / 2;
            c = (a * a + 1) / 2;

            if (b <= c && c <= n)
            {
                count++;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}