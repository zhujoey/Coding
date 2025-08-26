#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    long long n, p, farm[1001][1001], x, y, prevx, prevy, count = 0, startx, starty, endx, endy, temp;
    std::cin >> n >> p;
    --p;
    std::cin >> prevx >> prevy;
    while (p--)
    {
        std::cin >> x >> y;
        if (x == prevx)
        {
            if (y < prevy)
            {
                for (int i = prevy; i > y; --i)
                {
                    farm[i][x] = count;
                    ++count;
                }
            }
            else
            {
                for (int i = prevy; i < y; ++i)
                {
                    farm[i][x] = count;
                    ++count;
                }
            }
        }
        else
        {
            if (x < prevx)
            {
                for (int i = prevx; i > x; --i)
                {
                    farm[y][i] = count;
                    ++count;
                }
            }
            else
            {
                for (int i = prevx; i < x; ++i)
                {
                    farm[y][i] = count;
                    ++count;
                }
            }
        }
        prevx = x;
        prevy = y;
    }
    if (x == 0)
    {
        for (int i = y; i > 0; --i)
        {
            farm[i][x] = count;
            ++count;
        }
    }
    else
    {
        for (int i = x; i > 0; --i)
        {
            farm[y][i] = count;
            ++count;
        }
    }
    
    while (n--)
    {
        std::cin >> startx >> starty >> endx >> endy;
        temp = std::abs(farm[starty][startx] - farm[endy][endx]);
        std::cout << std::min(temp, count - temp) << "\n";
    }

    return 0;
}