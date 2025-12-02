#include <iostream>
#include <string>

int main()
{
    long long t, n, k;
    bool canplace, equal;
    char grid[20][20], stamp[20][20], ans[20][20], rotated[20][20];
    std::string useless, row;

    std::cin >> t;

    while (t--)
    {
        // full reset to safe defaults
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                grid[i][j] = '.';
                stamp[i][j] = '.';
                ans[i][j] = '.';
                rotated[i][j] = '.';
            }
        }

        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            std::cin >> row;
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = row[j];
            }
        }

        std::cin >> k;
        for (int i = 0; i < k; i++)
        {
            std::cin >> row;
            for (int j = 0; j < k; j++)
            {
                stamp[i][j] = row[j];
            }
        }

        for (int rot = 0; rot < 4; rot++)
        {
            for (int i = 0; i <= n - k; i++)
            {
                for (int j = 0; j <= n - k; j++)
                {
                    canplace = true;
                    for (int a = 0; a < k && canplace; a++)
                    {
                        for (int b = 0; b < k; b++)
                        {
                            if (!(grid[i + a][j + b] == '*' || stamp[a][b] == '.'))
                            {
                                canplace = false;
                                break;
                            }
                        }
                    }
                    if (canplace)
                    {
                        for (int a = 0; a < k; a++)
                        {
                            for (int b = 0; b < k; b++)
                            {
                                if (stamp[a][b] == '*')
                                {
                                    ans[i + a][j + b] = '*';
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    rotated[i][j] = stamp[k - 1 - j][i];
                }
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    stamp[i][j] = rotated[i][j];
                }
            }
        }

        equal = true;
        for (int i = 0; i < n && equal; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != ans[i][j])
                {
                    equal = false;
                    break;
                }
            }
        }

        if (equal)
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