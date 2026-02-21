
#include <iostream>

int main()
{
    int k, n, minspeed, first, second, timeused, curspeed;

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    std::cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> minspeed;

        first = 0;
        second = 0;
        timeused = 0;

        for (curspeed = 1; first + second < k; curspeed++)
        {
            first += curspeed;
            timeused++;

            if (curspeed >= minspeed && first + second < k)
            {
                second += curspeed;
                timeused++;
            }
        }

        std::cout << timeused << '\n';
    }

    return 0;
}
