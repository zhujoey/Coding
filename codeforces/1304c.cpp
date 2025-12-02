#include <iostream>
#include <algorithm>

int main()
{
    int tests, count, temp, low, high, time, gap, timearray[100], lowarray[100], higharray[100];
    bool possible;

    std::cin >> tests;

    while (tests--)
    {
        std::cin >> count >> temp;

        for (int i = 0; i < count; ++i)
        {
            std::cin >> timearray[i] >> lowarray[i] >> higharray[i];
        }

        low = temp;
        high = temp;
        time = 0;
        gap = 0;
        possible = true;

        for (int i = 0; i < count; ++i)
        {
            gap = timearray[i] - time;
            low -= gap;
            high += gap;

            low = std::max(low, lowarray[i]);
            high = std::min(high, higharray[i]);

            if (low > high)
            {
                possible = false;
            }

            time = timearray[i];
        }

        if (possible)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }

    return 0;
}