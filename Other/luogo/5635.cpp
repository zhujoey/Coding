#include <iostream>
#include <string>

int main()
{
    long long t, p, x, y, maxsteps, steps;
    std::string result;

    std::cin >> t >> p;

    for (int i = 0; i < t; ++i)
    {
        std::cin >> x >> y;
        maxsteps = 2 * p;
        steps = 0;
        result = "error";

        while (steps <= maxsteps)
        {
            if (x == 0)
            {
                result = "1";
                break;
            }
            if (y == 0)
            {
                result = "2";
                break;
            }
            if (steps % 2 == 0)
            {
                x = (x + y) % p;
            }
            else
            {
                y = (x + y) % p;
            }
            ++steps;
        }

        std::cout << result << '\n';
    }

    return 0;
}