#include <iostream>
#include <vector>
#include <string>

int main()
{
    int t, n, a, b, ans;
    bool end;
    std::vector<std::string> pic;
    std::string row;
    std::cin >> t;
    while (t--)
    {
        pic.clear();
        int orig[1000][1000] = {};
        ans = 0;
        end = false;
        std::cin >> n >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> row;
            pic.push_back(row);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pic[i][j] == 'B')
                {
                    if (i < b || j < a)
                    {
                        std::cout << -1 << "\n";
                        end = true;
                        break;
                    }
                    orig[i][j] = 2;
                    ++ans;
                    if (orig[i - b][j - a] == 1)
                    {
                        std::cout << -1 << "\n";
                        end = true;
                        break;
                    }
                    else if (orig[i - b][j - a] == 0)
                    {
                        orig[i - b][j - a] = 2;
                        ++ans;
                    }
                }
                else if (pic[i][j] == 'W')
                {
                    orig[i][j] = 1;
                }
            }
            if (end)
            {
                break;
            }
        }
        if (end)
        {
            continue;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pic[i][j] == 'G' && orig[i][j] == 0)
                {
                    if (i >= b && j >= a)
                    {
                        if (orig[i - b][j - a] == 1)
                        {
                            orig[i][j] = 2;
                            ++ans;
                        }
                        else
                        {
                            orig[i][j] = 1;
                        }
                    }
                    else
                    {
                        orig[i][j] = 2;
                        ++ans;
                    }
                    if (a == 0 && b == 0)
                    {
                        orig[i][j] = 2;
                        ++ans;
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}