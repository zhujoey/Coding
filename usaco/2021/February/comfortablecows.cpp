#include <iostream>

int main()
{
    int n, x, y, count = 0, newx, newy, newnewx, newnewy, neighbors, dir, k, dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, -1, 1};
    bool grass[1000][1000] = {false};

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> x >> y;

        for (dir = 0; dir < 4; ++dir)
        {
            newx = x + dirx[dir];
            newy = y + diry[dir];
            if (newx >= 0 && newx <= n && newy >= 0 && newy <= n)
            {
                if (grass[newx][newy])
                {
                    neighbors = 0;
                    for (k = 0; k < 4; ++k)
                    {
                        newnewx = newx + dirx[k];
                        newnewy = newy + diry[k];
                        if (newnewx >= 0 && newnewx <= n && newnewy >= 0 && newnewy <= n)
                        {
                            if (grass[newnewx][newnewy])
                            {
                                ++neighbors;
                            }
                        }
                    }
                    if (neighbors == 3)
                    {
                        --count;
                    }
                }
            }
        }

        grass[x][y] = true;

        for (dir = 0; dir < 4; ++dir)
        {
            newx = x + dirx[dir];
            newy = y + diry[dir];
            if (newx >= 0 && newx <= n && newy >= 0 && newy <= n)
            {
                if (grass[newx][newy])
                {
                    neighbors = 0;
                    for (k = 0; k < 4; ++k)
                    {
                        newnewx = newx + dirx[k];
                        newnewy = newy + diry[k];
                        if (newnewx >= 0 && newnewx <= n && newnewy >= 0 && newnewy <= n)
                        {
                            if (grass[newnewx][newnewy])
                            {
                                ++neighbors;
                            }
                        }
                    }
                    if (neighbors == 3)
                    {
                        ++count;
                    }
                }
            }
        }

        if (grass[x][y])
        {
            neighbors = 0;
            for (dir = 0; dir < 4; ++dir)
            {
                newx = x + dirx[dir];
                newy = y + diry[dir];
                if (newx >= 0 && newx <= n && newy >= 0 && newy <= n)
                {
                    if (grass[newx][newy])
                    {
                        ++neighbors;
                    }
                }
            }
            if (neighbors == 3)
            {
                ++count;
            }
        }

        std::cout << count << '\n';
    }

    return 0;
}