#include <iostream>
#include <algorithm>

int main()
{
    const int infinity = 1000000001;

    int n, currenttime, mintime, xi, yi, xj, yj, tj, stop, x[50], y[50], timestopped[50], t[50];
    bool di, dj, isnorth[50];
    char d;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> d >> x[i] >> y[i];
        isnorth[i] = d == 'N';
        timestopped[i] = infinity;
    }

    currenttime = 0;
    while (true)
    {
        mintime = infinity;

        for (int i = 0; i < n; i++)
        {
            t[i] = infinity;
            if (timestopped[i] == infinity)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    di = isnorth[i];
                    dj = isnorth[j];
                    xi = x[i];
                    yi = y[i];
                    xj = x[j];
                    yj = y[j];
                    tj = timestopped[j];

                    if (di == dj)
                    {
                        continue;
                    }

                    if (!di)
                    {
                        std::swap(xi, yi);
                        std::swap(xj, yj);
                    }

                    if (yj <= yi)
                    {
                        continue;
                    }

                    if (tj == infinity)
                    {
                        if (xi < xj - currenttime || xi >= xj + yj - yi)
                        {
                            continue;
                        }
                        stop = currenttime + yj - yi;
                    }
                    else
                    {
                        if (xi > xj || xi < xj - tj)
                        {
                            continue;
                        }
                        stop = currenttime + yj - yi;
                    }

                    if (stop < t[i])
                    {
                        t[i] = stop;
                    }
                }

                if (t[i] < mintime)
                {
                    mintime = t[i];
                }
            }
        }

        if (mintime == infinity)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            if (timestopped[i] == infinity)
            {
                if (isnorth[i])
                {
                    y[i] += (mintime - currenttime);
                }
                else
                {
                    x[i] += (mintime - currenttime);
                }
            }

            if (t[i] == mintime)
            {
                timestopped[i] = mintime;
            }
        }

        currenttime = mintime;
    }

    for (int i = 0; i < n; i++)
    {
        if (timestopped[i] == infinity)
        {
            std::cout << "Infinity\n";
        }
        else
        {
            std::cout << timestopped[i] << "\n";
        }
    }

    return 0;
}